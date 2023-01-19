#include "bits/stdc++.h"

using namespace std;
#define eps 1e-6
const int maxn = 100005;
const double PI = 3.14159265359;

int n, m;
double a[maxn];

int check(double x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        double temp = a[i];
        while (temp > x + eps) {
            temp -= x;
            cnt++;
        }
    }
    if (cnt >= m) return 1;
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        m++;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = 1.0 * a[i] * a[i];
            sum += a[i];
        }
        double l = 0.0, r = sum;
        double ans;
        while (r - l > eps) {
            double mid = (l + r) / 2.0;
            if (check(mid)) {
                ans = l;
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%.4f\n", ans * PI);
    }
}
/*
Sample Input
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2
 */

/*
Sample Output
25.1327
3.1416
50.2655
 */