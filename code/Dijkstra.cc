double dijkstra(vector<map<int,double>> &G, int s, int t) {
  priority_queue<pair<double,int>> heap;
  set<int> seen;
  heap.push({0,s});
  while(!heap.empty()) {
    pair<double,int> ud = heap.top();
    heap.pop();
    double d = ud.first;
    int u = ud.second;
    if(u == t) return -d;
    if(seen.find(u) != seen.end()) continue;
    seen.insert(u);
    for(auto p : G[u]) heap.push({d - p.second, p.first});
  }
  return -1;
}
