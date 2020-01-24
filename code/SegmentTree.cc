const int INF = 1e9;

// segment tree for minimum, maximum and sum
// root is in tree[1], children in tree[2i] and tree[2i+1]
// all ranges in build/updates/queries are 0-based
struct Node {
  int min, max, sum, upA, upB, size; // size of subtree
  void update(int a,int b) {
    min = a*min+b;
    max = a*max+b;
    if(a<0)
        swap(min,max);
    sum = a*sum + b*size;
    upA *= a;
    upB = a*upB+b;
  }
  Node() {
    min = INF;
    max = -INF;
    upB = sum = size = 0;
    upA = 1;
  }
};
Node *tree;
int N;
void compute(int v) { // update tree[v] from its children, v < N
  tree[v].min = min(tree[2*v].min, tree[2*v+1].min);
  tree[v].max = max(tree[2*v].max, tree[2*v+1].max);
  tree[v].sum = tree[2*v].sum + tree[2*v+1].sum;
}
// read values[0..size-1]
void build(int size, int values[]) {
  N = size > 1 ? 1 << ((int)log2(size-1)+1) : 1;
  tree = new Node[2*N];
  for(int i = 0; i < size; i++) { // leaves
    tree[N+i].min = tree[N+i].max = tree[N+i].sum = values[i];
    tree[N+i].size = 1;
  }
  for(int i = N-1; i > 0; i--) { // interns
    compute(i);
    tree[i].size = tree[2*i].size + tree[2*i+1].size;
  }
}
void push(int v) {
  if(2*v < 2*N) // left subtree
    tree[2*v].update(tree[v].upA,tree[v].upB);
  if(2*v+1 < 2*N) // right subtree
    tree[2*v+1].update(tree[v].upA,tree[v].upB);
  tree[v].upA=1; 
  tree[v].upB=0;
}

struct Infos
{
    int min,max,sum;
};
// v: current vertex with corressponding range [left, right)
// find minimum and sum of the range [l, r)
Infos query_aux(int v, int left, int right, int l, int r) {
  push(v);
  if(right <= l || r <= left) // outside
    return {INF,-INF,0};
  if(l <= left && right <= r) // inside
    return {tree[v].min, tree[v].max, tree[v].sum};
  int m = (left+right)/2;
  Infos linfo = query_aux(2*v, left, m, l, r); // left subtree
  Infos rinfo = query_aux(2*v+1, m, right, l, r); // right
  return {min(linfo.min, rinfo.min), max(linfo.max, rinfo.max), linfo.sum+rinfo.sum};
}

Infos query(int l, int r) {
  return query_aux(1, 0, N, l, r);
}
// update element at index i with value x
void update(int i, int x) {
  i+=N;
  // push path from 1 to i
  int po = N;
  for(int v = 1; v < i;) {
    push(v);
    v*=2;
    if(i & po)
      v++; // i on right
    po /= 2;
  }
  tree[i].min = tree[i].sum = x; // update el
  for(i /= 2; i > 0; i /= 2) // update all segments containing i
    compute(i);
}
// v: the current vertex with corressponding range in [left, right)
// add value x for element in range [l, r)
void update_range_aux(int v, int left, int right, int l, int r, int a, int b) {
  push(v);
  if(right <= l || r <= left)
    return;
  if(l <= left && right <= r) {
    tree[v].update(a,b);
    return;
  }
  int m = (left+right)/2;
  update_range_aux(2*v, left, m, l, r, a, b);
  update_range_aux(2*v+1, m, right, l, r, a, b);
  compute(v);
}
// update [l,r)
void update_range(int l, int r, int a, int b) {
  update_range_aux(1, 0, N, l, r, a, b);
}
