#include "bits/stdc++.h"

using namespace std;
const int maxn = 20000 + 10;
int pa[maxn], d[maxn];

int findset(int x) {
    if (pa[x] == x) return x;
    int root = findset(pa[x]);
    d[x] += d[pa[x]];
    return pa[x] = root;
}

int n, u, v;

int main() {
    int T;
    ::scanf("%d", &T);
    while (T--) {
        cin >> n;
        for (int i = 0; i < maxn; i++) {
            pa[i] = i;
            d[i] = 0;
        }
        string str;

        while (cin >> str) {
            if (str == "O") break;
            if (str == "E") {
                cin >> u;
                findset(u);
                ::printf("%d\n", d[u]);
            } else {
                cin >> u >> v;
                pa[u] = v;
                d[u] = abs(u - v) % 1000;
            }
        }
    }
}

/*
Sample Input
1
4
E 3
I 3 1
E 3
I 1 2
E 3
I 2 4
E 3
O
 */

/*
Sample Output
0
2
3
5
 */