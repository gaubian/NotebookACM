// ensemble d'entiers entre 0 et MAXN-1
typedef long long T;
const int MAXN = 5000;
const int BITS = (sizeof(T)*8);
const int SIZE = ((MAXN+BITS-1)/BITS); // size of arrays
void clear(T a[]) {
  memset(a, 0, sizeof(T[SIZE]));
}
void diff(T a[], T b[], T rep[]) {
  for(int i = 0; i < SIZE; i++)
    rep[i] = (a[i] ^ b[i]) & a[i];
}
void inter(T a[], T b[], T rep[]) {
  for(int i = 0; i < SIZE; i++)
    rep[i] = a[i] & b[i];
}
// union : idem with |
// symmetric difference : idem with ^
int size(T a[]) {
  int r = 0;
  for(int i = 0; i < SIZE; i++)
    r += __builtin_popcountll(a[i]); // pour long long
  return r;
}
void insert(T a[], int x) {
  a[x/BITS] |= ((T)1) << (x%BITS);
}
void del(T a[], int x) {
  a[x/BITS] &= ~(((T)1) << (x%BITS));
}
void print(T a[]) {
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < BITS; j++)
      if(a[i] & (((T)1)<<j))
        printf("%d ", i*BITS+j);
  printf("\n");
}
int getFirst(T a) { // return the smallest element in a, or -1 if a is empty
  return __builtin_ffsll(a)-1; // pour long long
}
bool test(T a[], int x) {
  return a[x/BITS] & (((T)1) << (x%BITS));
}
