// Given a string S of length n, the KMP algorithm produces an array pnext
// where pnext[i+1] is the length of the longest substring ending at S[i] which is also a prefix of S
vector<int> kmp_pre(string x) {
  int m = x.size();
  vector<int> pnext(m+1);
  int i,j;
  j=pnext[0]=-1;
  i=0;
  while (i<m) {
    while (-1!=j && x[i]!=x[j]) j=pnext[j];
    pnext[++i]=++j;
  }
  return kmp_pre;
}

// x pattern, y text
// answer: first index (starting with 0)
int KMP(string x, string y) { // KMP_Count
  int m = x.size(), n = y.size();
  int i = 0,j = 0;
  vector<int> pnext = kmp_pre(x);
  while(i<n) {
    while(-1!=j && y[i]!=x[j]) j=pnext[j];
    i++; j++;
    if(j >= m) return i-m;
  }
  return -1;
}
