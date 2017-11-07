struct vect {
  double x, y;
  vect(double a=0.0, double b=0.0) : x(a), y(b) {}
  double length() {
    return sqrt(x*x+y*y);
  }
  vect operator-(vect a) {
    return vect(x-a.x, y-a.y);
  }
};
double CP_Search(vect *s, vect *x[], vect *y[], int n, int &a, int &b, double d) {
  if(n == 1) return d;
  vect *z[maxn];
  int m = n>>1, p = 0;
  static bool u[maxn];
  for(int i = 0; i < m; i++) u[x[i]-s] = true;
  for(int i = 0, j = 0, k = m; i < n; i++)
    if(u[y[i]-s]) z[j++]=y[i]; else z[k++]=y[i];
  for(int i = 0; i < m; i++) u[x[i]-s] = false;
  d = CP_Search(s, x, z, m, a, b, d);
  d = CP_Search(s, x+m, z+m, n-m, a, b, d);
  for(int i = 0; i < n; i++)
    if(fabs(y[i]->x - x[m]->x)<d) z[p++] = y[i];
  for(int i = 0; i < p; i++)
    for(int j = i+1; j < p && z[j]->y - z[i]->y < d; j++) {
      double tmp = (*z[j] - *z[i]).length();
      if(d>tmp) { d=tmp; a=z[j]-s; b=z[i]-s; }
    }
  return d;
}
bool CP_cmpx(const vect *a, const vect *b) {
  return a->x < b->x;
}
bool CP_cmpy(const vect *a, const vect *b) {
  return a->y < b->y;
}
double ClosestPair(vect s[], int n, int &a, int &b) {
  vect *x[maxn], *y[maxn];
  for(int i = 0; i < n; i++)
    x[i] = y[i] = s+i;
  sort(x, x+n, CP_cmpx);
  sort(y, y+n, CP_cmpy);
  return CP_Search(s,x,y,n,a,b,INF);
}
