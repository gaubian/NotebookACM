#include <bits/stdc++.h>
#define fin(i, n) for(int i = 0; i < n; i++)
#define fin2(i, a, b) for(int i = a; i < b; i++)
#define debug(a) cerr << #a << " = " << (a) << endl;
using namespace std;
typedef unsigned int uint;
typedef long long L; // LL
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
// idem for VL, VVL, VD, VVD
const int INFI = 1000000000;
const L INF = numeric_limits<L>::max()/4;
const double EPS = 1e-8;
void parse() {}
void solve() {}
int main() {
  int T;
  scanf("%d", &T);
  fin2(i, 1, T) {
    parse();
    printf("Case #%d: ", i);
    solve();
    printf("\n");
    #ifdef DEBUG
      fprintf(stderr, "%d/%d = %.2fs (estim:%.2fs)\n", i, T, (double)clock ()/CLOCKS_PER_SEC, ((double)clock()/i*T)/CLOCKS_PER_SEC);
    #endif
  }
}
