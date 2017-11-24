using graph = map<int,set<int>>;

void Visit(int u, graph &G, stack<int> &st, set<int> &vis) {
    if(vis.find(u) != vis.end()) return;
    vis.insert(u);
    for(int v : G[u]) Visit(v,G,st,vis);
    st.push(u);
}

void Assign(graph &G, int u, int rt, map<int,int> &assi) {
    if(assi.find(u) != assi.end()) return;
    assi[u] = rt;
    for(int v : G[u]) Assign(G,v,rt,assi);
}

graph rev(graph &G) {
    graph Ans;
    for(pair<int,set<int>> p : G)
    for(int q : p.second) Ans[q].insert(p.first);
    return Ans;
}

map<int,int> SCC(graph &G) {
    set<int> vis;
    stack<int> st;
    map<int,int> assi;
    for(pair<int,set<int>> p : G) Visit(p.first,G,st,vis);
    graph GG = rev(G);
    while(!st.empty()) {
        int u = st.top();
        st.pop();	
        Assign(GG,u,u,assi);
    }
    return assi;
}
