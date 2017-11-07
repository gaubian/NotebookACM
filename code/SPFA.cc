
// SPFA O(kE).
struct Edge {
  int v, cost;
  Edge(int _v=0, int _cost=0): v(_v),cost(_cost){}
};
vector<Edge> E[MAXN];
void addedge(int u,int v,int w) {
  E[u].push_back(Edge(v, w));
}
bool vis[MAXN];// vis[i] i is in queue or not
int cnt[MAXN];// cnt[i]: i rentre cnt[i] fois dans la queue.
int dist[MAXN];
bool SPFA(int start,int n) {
  memset(vis, false, sizeof(vis));
  for(int i = 1; i <= n; i++) dist[i] = INF;
  vis[start] = true; dist[start] = 0;
  queue<int> que;
  while(! que.empty()) que.pop();
  que.push(start);
  memset(cnt, 0, sizeof(cnt));
  cnt[start] = 1;
  while(!que.empty()) {
    int u = que.front(); que.pop ();
    vis[u] = false;
    for(int i = 0; i < E[u].size(); i++) {
      int v = E[u][i].v;
      if(dist[v] > dist[u] + E[u][i].cost ) {
        dist[v] = dist[u] + E[u][i].cost;
        if(!vis[v]) {
          vis[v] = true;
          que.pus h(v);
          if(++cnt[v] > n) return false; //negatif circle
        }
      }
    }
  }
  return true;
}
