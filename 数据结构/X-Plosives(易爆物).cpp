#include "bits/stdc++.h"

using namespace std;
const int maxn = 100000 + 10;
int pa[maxn];

int findset(int x) {
    if (pa[x] == x) return x;
    return pa[x] = findset(pa[x]);
}

int main() {
    int x, y;
    while (cin >> x) {
        for (int i = 0; i < maxn; i++) pa[i] = i;
        int ans = 0;
        while (x != -1) {
            cin >> y;
            x = findset(x);
            y = findset(y);
            if (x == y) ans++;
            else pa[x] = y;
            cin >> x;
        }
        cout << ans << endl;
    }
}

/*
Sample Input
1 2
3 4
3 5
3 1
2 3
4 1
2 6
6 5
-1
 */

/*
Sample Output
3
 */