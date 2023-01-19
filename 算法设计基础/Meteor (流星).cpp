#include "bits/stdc++.h"

using namespace std;

const int N = 100000 + 10;


struct node {
    double x;
    int type;

    bool operator<(const node &a) const {
        if (x != a.x) return x < a.x;
        else return type > a.type;
    }
} p[N * 2];


void solve(int x, int v, int w, double &l, double &r) {
    if (v == 0) {
        if (x <= 0 || x >= w) r = l - 1;
    } else {
        if (v > 0) {
            l = max(l, -(double) x / v);
            r = min(r, double(w - x) / v);
        } else {
            l = max(l, (double) (w - x) / v);
            r = min(r, -(double) x / v);
        }
    }
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int w, h, n, cnt = 0;
        cin >> w >> h;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            double l = 0, r = 1e9;
            solve(x, a, w, l, r);
            solve(y, b, h, l, r);
            if (r > l) {
                p[cnt++] = {l, 0};
                p[cnt++] = {r, 1};
            }
        }
        sort(p, p + cnt);
        int temp = 0, ans = 0;
        for (int i = 0; i < cnt; i++) {
            if (p[i].type == 0) temp++;
            else temp--;
            ans = max(ans, temp);
        }
        cout << ans << endl;

    }
}

/*
Sample Input
2
4 2
2
-1 1 1 -1
5 2 -1 -1
13 6
7
3 -2 1 3
6 9 -2 -1
8 0 -1 -1
7 6 10 0
11 -2 2 1
-2 4 6 -1
3 2 -5 -1
 */

/*
Sample Output
1
2
 */