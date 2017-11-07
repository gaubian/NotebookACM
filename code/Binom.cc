/*
	C(n,k) + C(n,k+1) = C(n+1, k+1)

	C(n,k+1) = C(n,k) * (n-k)/(k+1)
*/
//Calculer c[n][k] for all k <= m.
int coeff_bin1(int n, int m){
	c[n][0] = 1;
	for (int k = 0; k < m; k++)
		c[n][k + 1] = c[n][k] * (n-k)/(k+1);
}
//Calculer tout
void coeff_bin2(int n, int m){
	memset(c, 0, sizeof(c));
	for (int i = 0; i <= n; i++) c[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
}
