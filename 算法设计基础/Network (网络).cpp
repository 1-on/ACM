#include "bits/stdc++.h"

using namespace std;

const int N = 1005;
vector<int> node[N], g[N];
int n, s, k;
int fa[N];
int covered[N];

void dfs(int u, int f, int d) {
    fa[u] = f;
    int size = g[u].size();
    if (size == 1 && d > k) node[d].push_back(u);
    for (int i = 0; i < size; i++) {
        int v = g[u][i];
        if (f != v) dfs(v, u, d + 1);
    }
}

void dfs2(int u, int f, int d) {
    covered[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != f && d < k) dfs2(v, u, d + 1);
    }
}

int solve() {
    int ans = 0;
    memset(covered, 0, sizeof(covered));
    for (int d = n - 1; d > k; d--) {
        for (int i = 0; i < node[d].size(); i++) {
            int v = node[d][i];
            if (covered[v]) continue;
            int f = v;
            for (int j = 0; j < k; j++)
                f = fa[f];
            dfs2(f, -1, 0);
            ans++;
        }
    }
    return ans;
}

int main() {
    int kase = 1;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s >> k;
        for (int i = 1; i <= n; ++i) {
            node[i].clear();
            g[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(s, -1, 0);
        cout << solve() << endl;
    }
}

/*
Sample Input
2 14
12 2
1 2
2 3
3 4
4 5
5 6
7 5
8 5
4 9
10 3
2 12
12 14
13 14
14 11
14
3 4
1 2
2 3
3 4
4 5
5 6
7 5
8 5
4 9
10 3
2 12
12 14
13 14
14 11
 */

/*
1
0
 */