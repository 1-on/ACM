#include "bits/stdc++.h"

using namespace std;
const int maxn = 1 << 17;
int n, m;
int vis[1010][2], d[1010][2];
vector<int> adj[1010];

int dp(int i, int j, int f) {
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int &ans = d[i][j];
    //放灯
    ans = 2000;
    for (int k = 0; k < adj[i].size(); k++) {
        if (adj[i][k] != f) {
            ans += dp(adj[i][k], 1, i);
        }
    }
    if (j == 0 && f >= 0) ans++;
    //不放灯
    if (j == 1 || f < 0) {
        int sum = 0;
        for (int k = 0; k < adj[i].size(); k++) {
            if (adj[i][k] != f) {
                sum += dp(adj[i][k], 0, i);
            }
        }
        if (f >= 0) sum++;
        ans = min(ans, sum);
    }
    return ans;

}

int main() {
    int T;
    ::scanf("%d", &T);
    while (T--) {
        ::scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) adj[i].clear();
        int a, b;
        for (int i = 0; i < m; i++) {
            ::scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ::memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i][0]) {
                ans += dp(i, 0, -1);
            }
        }
        ::printf("%d %d %d\n", ans / 2000, m - ans % 2000, ans % 2000);
    }
}

/*
Sample Input
2
4 3
0 1
1 2
2 3
5 4
0 1
0 2
0 3
0 4
 */

/*
Sample Output
2 1 2
1 0 4
 */