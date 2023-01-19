#include "bits/stdc++.h"

using namespace std;
const int MAXN = 250 * 250;
const int INF = 0x3f3f3f3f;
int N, p, q;
int S[MAXN], g[MAXN], d[MAXN];
int num[MAXN];

int main() {
    int T;
    cin >> T;
    int kase = 1;
    while (T--) {
        cin >> N >> p >> q;
        int x;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= p + 1; i++) {
            scanf("%d", &x);
            num[x] = i;
        }
        int n = 0;
        for (int i = 0; i < q + 1; i++) {
            scanf("%d", &x);
            if (num[x]) S[n++] = num[x];
        }

        memset(g, INF, sizeof(g));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = lower_bound(g + 1, g + 1 + n, S[i]) - g;
            d[i] = k;
            g[k] = S[i];
            ans = max(ans, d[i]);
        }
        printf("Case %d: %d\n", kase++, ans);
    }
}

/*
Sample Input
1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9
 */

/*
Sample Output
Case 1: 4
 */