#include "bits/stdc++.h"

using namespace std;
const int maxn = 1 << 17;
int n;
int dp[maxn], cover[maxn], link[maxn];

void init() {
    int m, k;
    ::memset(dp, 0, sizeof(dp));
    ::memset(cover, 0, sizeof(cover));
    ::memset(link, 0, sizeof(link));

    for (int i = 0; i < n; ++i) {
        ::scanf("%d", &m);
        link[i] |= (1 << i);
        for (int j = 0; j < m; j++) {
            ::scanf("%d", &k);
            link[i] |= (1 << k);
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) cover[i] |= link[j];
        }
    }
}

int solve() {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = i; j; j = (j - 1) & i) {
            if (cover[j] == (1 << n) - 1) {
                dp[i] = max(dp[i], dp[i ^ j] + 1);
            }
        }
    }
    return dp[(1 << n) - 1];
}

int main() {
    int kase = 1;
    while (::scanf("%d", &n) == 1 && n) {
        init();
        ::printf("Case %d: %d\n", kase++, solve());
    }
}

/*
Sample Input
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3
1 2
0
 */

/*
Sample Output
Case 1: 3
Case 2: 2
 */