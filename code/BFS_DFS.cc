// BFS and DFS with adjacency matrix G
void bfs(int from) {
// void dfs(int from) {
  queue<int> Q;
  // stack<int> Q;
  int visited[1000];
  memset(visited, 0, sizeof(visited));
  Q.push(from); // parent[from] = -1
  visited[from] = 1;
  while(!Q.empty()) {
    int s = Q.front();
    // int s = Q.top();
    Q.pop();
    for(int i = 1; i <= N; i++)
      if(G[s][i] && !visited[i]) {
        Q.push(i); // parent[i] = s
        visited[i] = 1;
      }
    // deal with s
  }
}
