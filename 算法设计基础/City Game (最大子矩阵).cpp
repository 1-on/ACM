#include "bits/stdc++.h"

using namespace std;

const int N = 1000 + 10;

int m, n;
char buf[N][N];
int up[N][N], left1[N][N], right1[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> buf[i][j];
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int lo = 0, ro = n + 1;
            for (int j = 1; j <= n; j++) {
                if (buf[i][j] == 'R') {
                    up[i][j] = left1[i][j] = 0;
                    lo = j;
                } else {
                    up[i][j] = i == 1 ? 1 : up[i - 1][j] + 1;
                    left1[i][j] = i == 1 ? lo + 1 : max(left1[i - 1][j], lo + 1);
                }
            }
            for (int j = n; j >= 1; j--) {
                if (buf[i][j] == 'R') {
                    right1[i][j] = n;
                    ro = j;
                } else {
                    right1[i][j] = i == 1 ? ro - 1 : min(right1[i - 1][j], ro - 1);
                    ans = max(ans, up[i][j] * (right1[i][j] - left1[i][j] + 1));
                }
            }
        }
        cout << ans * 3 << endl;

    }
}
/*
Sample Input
2
5 6
R F F F F R
F F F F F R
R R R F F F
F F F F F F
F F F F F F
5 5
R R R R R
R R R R R
R R R R R
R R R R R
R R R R R

 */

/*
Sample Output
45
0
 */