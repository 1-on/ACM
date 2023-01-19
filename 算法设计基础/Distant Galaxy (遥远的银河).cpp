#include "bits/stdc++.h"

using namespace std;

const int N = 100 + 10;
int n, m;
int lef[N], on[N], on2[N], y[N];

struct Point {
    int x, y;

    bool operator<(const Point &rhs) const {
        return x < rhs.x;
    }
} P[N];

int solve() {
    sort(P + 1, P + 1 + n);
    sort(y + 1, y + 1 + n);

    int m = unique(y + 1, y + 1 + n) - y - 1;
    if (m <= 2) return n;
    int ans = 0;
    for (int a = 1; a <= m; a++) {
        for (int b = a + 1; b <= m; b++) {
            int ymin = y[a], ymax = y[b];
            int k = 0;
            for (int i = 1; i <= n; i++) {
                if (i == 1 || P[i].x != P[i - 1].x) {
                    k++;
                    on[k] = on2[k] = 0;
                    lef[k] = k == 1 ? 0 : lef[k - 1] + on2[k - 1] - on[k - 1];
                }
                if (P[i].y > ymin && P[i].y < ymax) on[k]++;
                if (P[i].y >= ymin && P[i].y <= ymax) on2[k]++;
            }
            if (k <= 2) return n;
            int M = 0;
            for (int j = 1; j <= k; j++) {
                ans = max(ans, on2[j] + lef[j] + M);
                M = max(M, on[j] - lef[j]);
            }
        }
    }
    return ans;
}

int main() {
    int kase = 1;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> P[i].x >> P[i].y;
            y[i] = P[i].y;
        }
        printf("Case %d: %d\n", kase++, solve());
    }
}

/*
Sample Input
10
2 3
9 2
7 4
3 4
5 7
1 5
10 4
10 6
11 4
4 6
0
 */

/*
Sample Output
Case 1: 7
 */