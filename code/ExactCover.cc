const int maxn = 1000;
const int maxnode = 1000;
const int maxr = 1000;
// l'algorithme X + Dancing links.
struct DLX {
  int n, sz; //nb de colonne, nb de noeuds.
  int S[maxn]; //nb de noeuds dans chaque colonne.
  int row[maxnode], col[maxnode]; // index de ligne et colonne pour chaque noeud.
  int L[maxnode], R[maxnode], U[maxnode], D[maxnode];
  int ansd, ans[maxr]; //solution
  void init(int n) {
    this->n = n;
    // noeud virtuel
    for(int i = 0 ; i <= n; i++) {
      U[i] = i; D[i] = i; L[i] = i-1, R[i] = i+1;
    }
    R[n] = 0; L[0] = n;
    sz = n + 1;
    memset(S, 0, sizeof(S));
  }
  void addRow(int r, VI columns) {
    int first = sz;
    for(int i = 0; i < columns.size(); i++) {
      int c = columns[i];
      L[sz] = sz - 1; R[sz] = sz + 1; D[sz] = c; U[sz] = U[c];
      D[U[c]] = sz; U[c] = sz;
      row[sz] = r; col[sz] = c;
      S[c]++; sz++;
    }
    R[sz - 1] = first; L[first] = sz - 1;
  }
  #define FOR(i,A,s) for(int i = A[s]; i != s; i = A[i])
  void remove(int c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    FOR(i,D,c)
      FOR(j,R,i) { U[D[j]] = U[j]; D[U[j]] = D[j]; --S[col[j]]; }
  }
  void restore(int c) {
    FOR(i,U,c)
      FOR(j,L,i) { ++S[col[j]]; U[D[j]] = j; D[U[j]] = j; }
    L[R[c]] = c;
    R[L[c]] = c;
  }
  bool dfs(int d) { //d : depth
    if (R[0] == 0) { // Found the solution
      ansd = d; // the length of the solution
      return true;
    }
    // Find the column c which has the minimum S.
    int c = R[0]; //the first column non-deleted
    FOR(i,R,0) if(S[i] < S[c]) c = i;
    remove(c);
    FOR(i,D,c) {
      ans[d] = row[i];
      FOR(j,R,i) remove(col[j]); //Delete all columns covered by i-th line.
      if(dfs(d+1)) return true;
      FOR(j,L,i) restore(col[j]); // Undo
    }
    restore(c);
    return false;
  }
  bool solve(VI& v) {
    v.clear();
    if(!dfs(0)) return false;
    for(int i = 0; i < ansd; i++) v.push_back(ans[i]);
    return true;
  }
};
void test() {
  DLX solver;
  solver.init(7);
  // parmi ces 6 ensembles, existe-t-il une couverture exacte de 1..7?
  VI v1 = {1,4,7}; VI v2 = {1,4}; VI v3 = {4,5,7};
  VI v4 = {3,5,6}; VI v5 = {2,3,6,7}; VI v6 = {2,7};
  solver.addRow(1, v1); solver.addRow(2, v2); solver.addRow(3, v3); solver.addRow(4, v4); solver.addRow(5, v5); solver.addRow(6, v6);
  VI ans;
  solver.solve(ans);
  for (int i = 0; i < ans.size(); i++)
    cout<< ans[i] << endl;
  if (ans.size() == 0)
    cout << "Non solution" <<endl;
}
