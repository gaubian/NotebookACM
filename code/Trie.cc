struct node { char a; int b,c,n; };
// Set r = -1 for the first call to insert
int insert(int *r, const char *s, node t[], int &m) {
  if(!*s) return 0;
  while(true) {
    while(*r != -1 && t[*r].a != *s) r = &t[*r].b;
    if(*r == -1) {
      t[m].a=*s;
      t[m].b = t[m].c = -1;
      t[m].n = 0;
      *r=m++;
    }
    if(*++s) r=&(t[*r].c);
    else return ++t[*r].n;
  }
}
// return -1=Not found, 0=not found but preffix, >0=found
int match(int r, const char *s, node*t) {
  if(!*s) return -1;
  while(true) {
    while(r!=-1 && t[r].a != *s) r=t[r].b;
    if(r == -1) return -1;
    if(*++s) r=t[r].c; else return t[r].n;
  }
}
void test() {
  node n[256];
  int r = -1, m;
  insert(&r, "coucou", n, m);
  insert(&r, "ca", n, m);
  insert(&r, "va", n, m);
  assert(match(r, "coucou", n) > 0);
  assert(match(r, "ca", n) > 0);
  assert(match(r, "va", n) > 0);
  assert(match(r, "c", n) == 0);
  assert(match(r, "co", n) == 0);
  assert(match(r, "z", n) == -1);
  assert(match(r, "v", n) == 0);
}
