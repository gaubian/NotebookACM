// Using Union-find
struct edge{ int u,v,w; };
bool Kruskal_cmp(const edge *a, const edge *b) {
  return a->w<b->w;
}
// Return -1 if no tree found.
int Kruskal(int n, int m, edge e[], int ret[]) {
  if(n==1) return 0;
  static edge *d[maxm];
  for(int i=0; i<m; i++) d[i] = e+i;
  sort(d, d+m, Kruskal_cmp);
  int f[maxn], c=0;
  make(f,i);
  for(int i=0, j=0; i<m; i++)
    if(find(f, d[i]->u) != find(f, d[i]->v)) {
      unite(f,d[i]->u,d[i]->v);
      c+=d[i]->w;
      ret[j]=d[i]-e;
      if(++j==n-1) return c;
    }
  return -1;
}
