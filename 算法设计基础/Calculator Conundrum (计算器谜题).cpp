#include "bits/stdc++.h"

using namespace std;

const int N = 100000 + 10;

int n, k;
map<long long, int> map1;

int main() {
    int T;
    cin >> T;
    while (T--) {
        map1.clear();
        cin >> n >> k;
        long long temp = k;
        int ans = k;
        map1[k]++;


        while (1) {
            temp = temp * temp;
            while (temp >= pow(10.0, n)) {
                temp /= 10;
            }
            //cout<<temp<<endl;
            if (temp > ans) ans = temp;
            map1[temp]++;
            if (map1[temp] == 2) break;
        }
        cout << ans << endl;
    }
}

/*
Sample Input
2
1 6
2 99
 */

/*
Sample Output
9
99
 */