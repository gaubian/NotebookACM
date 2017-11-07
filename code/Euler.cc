// euler({{{1,1},{2,1}}, {{0,1},{2,1}}, {{0,1},{1,1}}}) = {true,{0,1,2}}
pair<bool,vector<int>> euler(vector<map<int,int>> grph) {
  vector<int> ans;
  bool solved = true;
  function <void(int)> aux = [&](int u) {
    for(pair<int,int> nei : grph[u])
      if(nei.second > 0) {
        int v = nei.first ;
        grph[u][v]--; grph[v][u]--; //only G[u][v]-- for directed
        aux(v);
        ans.push_back(v);
      }
  };
  for(int i = 0; i < grph.size() ; i++) { // #in = #out for directed
    int ans = 0;
    for(pair<int,int> nei : grph[i]) ans += nei.second ;
    if(ans % 2 == 1) solved = false ;
  }
  aux(0) ;
  if(!solved) return {false, ans};
  else return {true,ans};
}
