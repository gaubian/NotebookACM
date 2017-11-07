int dfs_clock = 0;
int iscut[maxn];
int low[maxn], pre[maxn];
//appeler: dfs(u, -1).
//Initialisation:
//	memset(pre, 0, sizeof(pre));
//	memset(iscut, false, sizeof(iscut);
//Complexite: O(n+m)
int dfs(int u, int fa){ // u's father is fa.
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if (!pre[v]) {
			child ++;
			int lowv =dfs(v, u);
			lowu = min(lowu, lowv);
			//if (lowv > pre[u]) { isbridge[u][v] = true; }
			if (lowv >= pre[u]){
				iscut[u] = true;
			}
		}
		else if (pre[v] < pre[u] && v != fa){
			lowu = min(lowu, pre[v]);
		}
	}

	if (fa < 0 && child == 1) iscut[u] = 0;
	low[u] = lowu;
	return lowu;
}
