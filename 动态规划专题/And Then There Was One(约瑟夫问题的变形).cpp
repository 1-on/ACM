#include "bits/stdc++.h"

using namespace std;
const int N = 25;


int main() {
    int n, m, k;
    while (cin >> n >> k >> m && n) {
        int s = 0;
        for (int i = 2; i <= n - 1; i++) {
            s = (s + k) % i;
        }
        printf("%d\n", (s + m) % n + 1);
    }
}

/*
Sample Input
8 5 3
100 9999 98
10000 10000 10000
0 0 0
 */

/*
Sample Output
1
93
2019
 */