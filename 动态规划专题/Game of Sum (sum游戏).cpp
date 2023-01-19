#include "bits/stdc++.h"

using namespace std;
const int maxn = 100 + 10;

int S[maxn];
int d[maxn][maxn], vis[maxn][maxn];
int a[maxn];
int n;


int dp(int i, int j) {
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int m = 0;
    for (int k = i + 1; k <= j; k++) m = min(m, dp(k, j));
    for (int k = i; k < j; k++) m = min(m, dp(i, k));
    d[i][j] = S[j] - S[i - 1] - m;
    return d[i][j];
}

int main() {
    while (cin >> n && n) {
        S[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S[i] = S[i - 1] + a[i];
        }
        memset(vis, 0, sizeof(vis));
        cout << 2 * dp(1, n) - S[n] << endl;
    }
}

/*
Sample Input
4
4 -10 -20 7
4
1 2 3 4
0
 */

/*
Sample Output
7
10
 */