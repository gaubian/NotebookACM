//return a^p (mod n)
int pow_mod(int a, int p, int n){
	if (p == 0) return 1;
	int ans = pow_mod(a, p/2, n);
	ans = (ans*ans) % n;
	if (p % 2 == 1) ans = (ans*a) % n;
	return ans;
}
// Baby-Step-Giant-Step Algorithm. O(n^(0.5)*logn)
// solve a^x = b (mod n). Return -1 for non solution
int log_mod(int a, int b, int n) {
	int m, v, e = 1, i;
	m = (int) sqrt(n + 0.5);
	v = mod_inverse(pow_mod(a, m, n), n);
	map <int , int > x;
	x[1] = 0;
	for (i = 1; i < m; i++) {
		e = (e * a) % n;
		if (!x.count(e)) x[e] = i;
	}
	for (i = 0; i < m; i++){
		if (x.count(b)) return i*m + x[b];
		b = (b * v) % n;
	}
	return -1;
}
