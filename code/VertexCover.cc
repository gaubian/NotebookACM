pair<set<int>,set<int>> from_matching(graph &w, VI &l, VI &r) {
    set<int> L, R;
    stack<int> st;
    for(int i = 0; i < l.size(); ++i) if(l[i] == -1) st.push(i);
    for(int i = 0; i < l.size(); ++i) L.insert(i);
    while(!st.empty()) {
	int x = st.top();
	st.pop();
	if(L.find(x) == L.end()) continue;
	L.erase(x);
	for(int y : w[x])
	    if(y != l[x]) {
		R.insert(y);
		st.push(r[y]);
	    }
    }
    return {L,R};
}
