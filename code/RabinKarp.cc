// recherche de motif 2D
// input : text n*m matrix; pattern x*y matrix
const int A=2001, B = 2001; // maximum sizes
const uint E=27;
char text[A][A], patt[B][B]; // [x][y]
uint ht, hp, pw[B*B], hor[A], ver[A][A];
int n, m, x, y;
void init() { // call only once
  int i, j = B*B;
  for(i=1, pw[0]=1; i<j; ++i) pw[i]=pw[i-1]*E;
}
void hash() { // call before count
  int i, j;
  for(i=0; i<n; ++i)
    for(j=0, hor[i]=0; j<y; ++j) {
      hor[i]*=pw[x]; hor[i]+=text[i][j]-'a';
    }
  for(j=0; j<m; ++j) {
    for(i=0, ver[0][j]=0; i<x; ++i) {
      ver[0][j]*=E; ver[0][j]+=text[i][j]-'a';
    }
    for(i=1; i<=n-x; ++i)
      ver[i][j]=(ver[i-1][j]-(text[i-1][j]-'a')*pw[x-1])
        *E+text[i+x-1][j]-'a';
  }
  for(j=0, ht=hp=0; j<y; ++j)
    for(i=0; i<x; ++i) {
      ht*=E; ht+=text[i][j]-'a';
      hp*=E; hp+=patt[i][j]-'a';
    }
}
int count() {
  if (n==0||m==0||x==0||y==0) return 0;
  int i, j, cnt=0; uint t;
  for(i=0; i<=n-x; ++i) {
    for(j=0, t=ht; j<=m-y; ++j) {
      if(t==hp) ++cnt;
      t=(t-ver[i][j]*pw[y*x-x])*pw[x]+ver[i][j+y];
    }
    ht=(ht-hor[i]*pw[x-1])*E+hor[i+x];
  }
  return cnt;
}
