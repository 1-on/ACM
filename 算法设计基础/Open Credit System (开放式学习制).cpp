#include "bits/stdc++.h"

using namespace std;

const int N = 100000 + 10;

int n;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = -15000;
        int temp = a[1];
        for (int i = 2; i <= n; i++) {
            if (temp - a[i] > ans) ans = temp - a[i];
            if (a[i] > temp) temp = a[i];
        }
        cout << ans << endl;
    }
}

/*
Sample Input
3
2
100
20
4
4
3
2
1
4
1
2
3
4
*/

/*
Sample Output
80
3
-1
 */