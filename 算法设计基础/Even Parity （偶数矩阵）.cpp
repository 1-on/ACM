#include "bits/stdc++.h"

using namespace std;
#define INF 0x3f3f3f3f
const int N = 20;

int a[N][N];
int b[N][N];
int T, n;

int get(int x) {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        if (x & 1) {
            b[1][i] = 1;
        } else {
            if (a[1][i] == 1) return INF;
        }
        x >>= 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            if (i - 2 > 0) sum += b[i - 2][j];
            if (j - 1 > 0) sum += b[i - 1][j - 1];
            if (j + 1 <= n) sum += b[i - 1][j + 1];
            sum %= 2;
            if (sum == 0 && a[i][j] == 1) return INF;
            b[i][j] = sum;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != b[i][j]) sum++;
        }
    }
    return sum;
}

int main() {
    int kase = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int num = 1 << n, MIN = INF;
        for (int i = 0; i < num; i++) {
            MIN = min(MIN, get(i));
        }
        if (MIN == INF) printf("Case %d: -1\n", ++kase);
        else printf("Case %d: %d\n", ++kase, MIN);
    }
}

/*
Sample Input
3
3
0 0 0
0 0 0
0 0 0
3
0 0 0
1 0 0
0 0 0
3
1 1 1
1 1 1
0 0 0
 */

/*
Sample Output
Case 1: 0
Case 2: 3
Case 3: -1
 */