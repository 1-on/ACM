#include "bits/stdc++.h"

using namespace std;
const int N = 1000000 + 10;
int n, m;
int a[N];
vector<int> pos[N];

int main() {
    while (::scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < N; i++) pos[i].clear();
        for (int i = 0; i < n; i++) {
            ::scanf("%d", &a[i]);
            pos[a[i]].push_back(i + 1);
        }
        while (m--) {
            int k, v;
            ::scanf("%d %d", &k, &v);
            if (pos[v].empty()) ::printf("0\n");
            else if (pos[v].size() < k) ::printf("0\n");
            else ::printf("%d\n", pos[v][k - 1]);
        }
    }
}

/*\
Sample Input
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2
 */

/*
Sample Output
2
0
7
0
 */