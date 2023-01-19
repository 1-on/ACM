#include "bits/stdc++.h"

using namespace std;

const int N = 2000000 + 10;

int n;
int a[N];

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        printf("%d", a[0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
}

/*
Sample Input
5
3 4 2 1 5
5
2 3 2 3 1
0
 */

/*
Sample Output
1 2 3 4 5
1 2 2 3 3
 */