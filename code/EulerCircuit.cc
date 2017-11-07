struct Edge {
  int from, to;
  Edge(int from, int to):from(from),to(to) {}
};
int n; // nombre de sommets.
int G[maxn][maxn]; // G[i][j]= # d'aretes i->j
int deg[i];
vector<Edge> ans; // resultat.
void euler(int u){
  	for(int v = 1; v <= n; v++) if(G[u][v]) {
    	G[u][v]--; G[v][u]--; //only G[u][v]--; for directed graph.
    	euler(v);
    	ans.push_back(Edge(u, v));
  	}
}
int solve_euler_path() {
 	bool solved = true;
 	for(int i = 1; i <= n; i++)
 		if(deg[i] % 2 == 1) { solved = false; break; } 
 		if(solved) {
      		ans.clear();
      		euler(start);
      		if(ans.size() != n || ans[0].to != ans[ans.size()-1].from) solved = false;
    	}
    return solved;
}
