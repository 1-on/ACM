#include "bits/stdc++.h"

using namespace std;
const int N = 25;

int a, b, c;
long long arr[N][N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        memset(arr, 0, sizeof(arr));
        for (int k = 1; k <= a; k++) {
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= c; j++) {
                    cin >> arr[k][i][j];
                    arr[k][i][j] += arr[k][i - 1][j] + arr[k][i][j - 1] - arr[k][i - 1][j - 1];
                }
            }
        }

        long long sum, maxsum, ans = arr[1][1][1];
        //上下行
        for (int m = 1; m <= b; m++)
            for (int n = m; n <= b; n++)
                //左右列
                for (int p = 1; p <= c; p++)
                    for (int q = p; q <= c; q++) {
                        //层
                        maxsum = 0;
                        for (int x = 1; x <= a; x++) {
                            sum = arr[x][n][q] - arr[x][m - 1][q] - arr[x][n][p - 1] + arr[x][m - 1][p - 1];
                            maxsum = max(maxsum + sum, sum);
                            ans = max(ans, maxsum);
                        }
                    }
        cout << ans << endl;
        if (T) cout << endl;

    }
}
/*
Sample Input
1
2 2 2
-1 2 0 -3 -2 -1 1 5
 */

/*
Sample Output
6
 */