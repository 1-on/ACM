#include "bits/stdc++.h"

using namespace std;

char buf[15][15];
int n;

int main() {
    int kase = 1;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> buf[i][j];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (buf[i][j] == '.') {
                    for (int k = 0; k < 26; k++) {
                        char c = 'A' + k;
                        if (buf[i - 1][j] == c || buf[i + 1][j] == c || buf[i][j - 1] == c ||
                            buf[i][j + 1] == c)
                            continue;
                        buf[i][j] = c;
                        break;
                    }
                }
            }
        }
        printf("Case %d:\n", kase++);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << buf[i][j];
            }
            cout << endl;
        }
    }
}

/*
Sample Input
2
3
...
...
...
3
...
A..
...
...
 */

/*
Sample Output
Case 1:
ABA
BAB
ABA
Case 2:
BAB
ABA
BAB
 */