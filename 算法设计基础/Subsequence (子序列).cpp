#include "bits/stdc++.h"

using namespace std;

const int N = 100000 + 10;

int n, s;
int a[N];

int check(int x) {
    long long sum = 0;
    for (int i = 0; i < x; i++) {
        sum += a[i];
    }
    if (sum >= s) return 1;
    for (int i = x; i < n; i++) {
        sum -= a[i - x];
        sum += a[i];
        if (sum >= s) return 1;
    }
    return 0;
}

int main() {
    while (cin >> n >> s) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 0, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            //cout<<mid<<endl;
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
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5
 */

/*
Sample Output
2
3
 */