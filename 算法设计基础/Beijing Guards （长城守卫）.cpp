#include "bits/stdc++.h"

using namespace std;

const int N = 100005;

int n;
int a[N];
int left1[N], right1[N];

int check(int p) {
    int x, y;
    left1[1] = a[1];
    right1[1] = 0;
    x = a[1], y = p - a[1];
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            left1[i] = min(a[i], x - left1[i - 1]);
            right1[i] = a[i] - left1[i];
        } else {
            right1[i] = min(a[i], y - right1[i - 1]);
            left1[i] = a[i] - right1[i];
        }
    }
    if (left1[n] == 0) return 1;
    return 0;
}

int main() {
    while (cin >> n && n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum = max(sum, a[i] * 3);
        }
        if (n == 1) {
            cout << a[1] << endl;
            continue;
        }
        int l = 0, r = sum;
        a[n + 1] = a[1];
        for (int i = 1; i <= n; i++) {
            l = max(l, a[i] + a[i + 1]);
        }
        if (n % 2 == 0) {
            cout << l << endl;
            continue;
        }
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}

/*
Sample Input
3
4
2
2
5
2
2
2
2
2
5
1
1
1
1
1
0
 */

/*
Sample Output
8
5
3
 */