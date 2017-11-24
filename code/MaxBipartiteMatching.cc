bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for(int j : w[i]) if(!seen[j]) {
    seen[j] = true;
    if(mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
      mr[i] = j;
      mc[j] = i;
      return true;
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc, int N, int M) {
  mr = VI(N, -1);
  mc = VI(M, -1);
  int ct = 0;
  for(int i = 0; i < N; i++) {
    VI seen(M);
    if(FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}
