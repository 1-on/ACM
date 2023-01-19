#include "bits/stdc++.h"

using namespace std;

int n, start[70], end1[70];

long long fun(int *p, int i, int target) {
    if (i == 0) return 0;
    if (p[i] == target) return fun(p, i - 1, target);
    return fun(p, i - 1, 6 - p[i] - target) + (1LL << (i - 1));
}

int main() {
    int kase = 1;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) cin >> start[i];
        for (int i = 1; i <= n; i++) cin >> end1[i];
        int k = n;
        while (k >= 1 && start[k] == end1[k]) {
            k--;
        }
        long long ans = 0;
        if (k >= 1) {
            int target = 6 - start[k] - end1[k];
            ans = fun(start, k - 1, target) + fun(end1, k - 1, target) + 1;
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
}
/*
Sample Input
3
1 1 1
2 2 2
3
1 2 3
3 2 1
4
1 1 1 1
1 1 1 1
0
 */
/*
Sample Output
Case 1: 7
Case 2: 3
Case 3: 0
 */