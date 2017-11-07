#define INF 0x7fffffff
const int maxn = 101;
int a[maxn][maxn];    // matrice adjacente
int pre[maxn][maxn];    // pre[i][j] = the previous node of j in the path from i to j.
int dist[maxn][maxn];
int n;
//O(n^3)
void floyd() {
    //initialisation
    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= n; j++)
            if (a[i][j]) {
                dist[i][j] = a[i][j]; pre[i][j] = i;
            }
            else {
                dist[i][j] = INF; pre[i][j] = -1;
            }
    //floyd
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1;j <= n ; j++)
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
}
