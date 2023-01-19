#include "bits/stdc++.h"

using namespace std;

#define FOR(i, n) for(int i=0;i<(n);i++)

const int maxn = 10;
int view[6][maxn][maxn];
int pos[maxn][maxn][maxn];
int n;

char read_char() {
    char ch;
    while (1) {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || ch == '.') return ch;
    }
}

void get(int k, int i, int j, int len, int &x, int &y, int &z) {
    if (k == 0) { x = len, y = j, z = i; }
    if (k == 1) { x = n - 1 - j, y = len, z = i; }
    if (k == 2) { x = n - 1 - len, y = n - 1 - j, z = i; }
    if (k == 3) { x = j, y = n - 1 - len, z = i; }
    if (k == 4) {
        x = n - 1 - i;
        y = j, z = len;
    }
    if (k == 5) { x = i, y = j, z = n - 1 - len; }
}

int main() {
    while (cin >> n && n) {
        FOR(i, n) FOR(k, 6) FOR(j, n) view[k][i][j] = read_char();
        FOR(i, n) FOR(j, n) FOR(k, n) pos[i][j][k] = '#';

        FOR(k, 6) FOR(i, n) FOR(j, n) if (view[k][i][j] == '.')
                        FOR(p, n) {
                            int x, y, z;
                            get(k, i, j, p, x, y, z);
                            pos[x][y][z] = '.';
                        }
        while (true) {
            bool done = true;
            FOR(k, 6) FOR(i, n) FOR(j, n) if (view[k][i][j] != '.') {
                            FOR(p, n) {
                                int x, y, z;
                                get(k, i, j, p, x, y, z);
                                if (pos[x][y][z] == '.') continue;
                                if (pos[x][y][z] == '#') {
                                    pos[x][y][z] = view[k][i][j];
                                    break;
                                }
                                if (pos[x][y][z] == view[k][i][j]) {
                                    break;
                                }
                                pos[x][y][z] = '.';
                                done = false;
                            }
                        }
            if (done) break;
        }
        int ans = 0;
        FOR(i, n) FOR(j, n) FOR(k, n)if (pos[i][j][k] != '.') ans++;

        printf("Maximum weight: %d gram(s)\n", ans);
    }
}

/*
Sample Input
3
.R. YYR .Y. RYY .Y. .R.
GRB YGR BYG RBY GYB GRB
.R. YRR .Y. RRY .R. .Y.
2
ZZ ZZ ZZ ZZ ZZ ZZ
ZZ ZZ ZZ ZZ ZZ ZZ
0
 */

/*
Sample Output
Maximum weight: 11 gram(s)
Maximum weight: 8 gram(s)
 */