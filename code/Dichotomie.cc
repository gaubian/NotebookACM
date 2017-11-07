// example of binary search
int dicho(int pos, int size) {
  int l = 0, r = size-1;
  while(l < r) {
    int m = l+(r-l)/2;
    if(pos <= m) // replace with predicate
	  r = m;
    else
	  l = m+1;
  }
  return l;
}
