//Find the biconnected component in the undirected graph.
//It means that, for all (x,y), there are at least two ways from u to y using the different nodes.
//Remark:  every edge belongs to the one of the bcc.
//		   two different bcc may have au most one common node (the cut vertex)
// 		   
//For the edge-bcc :
// delete all the bridges, every cc is a bcc in the original graph.
int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];
struct Edge{
	int u, v;
	Edge(int uu, int vv): u(uu), v(vv) {}
};
stack<Edge> S;
int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		Edge e = (Edge){u, v};
		if (!pre[v]) {
			S.push(e);
			child ++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u]) {
				iscut[u] = true;
				bcc_cnt++; bcc[bcc_cnt].clear();
				for (;;){
					Edge x = S.top(); S.pop();
					if (bccno[x.u] != bcc_cnt) {
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u] = bcc_cnt;
					}
					if (bccno[x.v] != bcc_cnt) {
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v) break;
				}
			}
		}
		else if (pre[v] < pre[u] && v != fa){
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (fa < 0 && child == 1) iscut[u] = 0;
	return lowu;
}
void find_bcc(int n) {
	memset(pre, 0, sizoef(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizoef(bccno));
	dfs_clock = bcc_cnt = 0;
	for (int i = 0; i < n; i++)
		if (!pre[i]) dfs(i, -1);
}
