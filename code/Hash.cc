unsigned long long H[maxn], xp[maxn];
unsigned long long hash[maxn];
//We can choose different value of x to double-check our hash function.
const int x = 123;
//using unsigned long long  <->   % (1<<64)
//s: original string
void hash() {
	H[n] = 0;
	for(int i = n-1; i >= 0; i--) H[i] = H[i+1] * x + (s[i] - 'a');
	xp[0] = 1;
	for(int i = 1; i <= n; i++) xp[i] = xp[i-1] * x;
	//the hash value of the S[i]..S[i+L-1].
	//Hash(i,L) = H(i)-H(i+L)x^L
  // ----->    hash[i] = H[i] - H[i+L]*xp[L];
}
