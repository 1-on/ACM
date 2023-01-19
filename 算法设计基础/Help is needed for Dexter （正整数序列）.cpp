#include "bits/stdc++.h"

using namespace std;


int main() {
    long long n;
    while (cin >> n) {
        int ans = 0;
        while (n) {
            ans++;
            n /= 2;
        }
        cout << ans << endl;
    }
}
/*
Sample Input
1
2
3
 */

/*
Sample Output
1
2
2
 */