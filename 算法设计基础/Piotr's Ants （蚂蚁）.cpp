#include "bits/stdc++.h"

using namespace std;
int N;
int L, T, n;
struct node2 {
    int pos;
    string fangxiang;
} a[20010];
int flag[2001000];

int order[20010];
struct node {
    int pos;
    int id;
} start[20010];

bool cmp(node x, node y) {
    return x.pos < y.pos;
}

bool cmp2(node2 x1, node2 y1) {
    return x1.pos < y1.pos;
}

int main() {
    cin >> N;
    int pos;
    string d;
    int kase = 1;
    while (N--) {
        memset(flag, 0, sizeof(flag));
        cin >> L >> T >> n;
        for (int i = 0; i < n; i++) {
            cin >> pos >> d;
            start[i].pos = pos;
            start[i].id = i;
            a[i].fangxiang = d;
            if (d == "L") {
                a[i].pos = pos - T;
            } else {
                a[i].pos = pos + T;
            }
        }
        sort(start, start + n, cmp);
        for (int i = 0; i < n; i++) {
            order[start[i].id] = i;
        }

        printf("Case #%d:\n", kase++);

        sort(a, a + n, cmp2);
        for (int i = 0; i < n - 1; i++) {
            if (a[i].pos == a[i + 1].pos)
                a[i].fangxiang = a[i + 1].fangxiang = "turn";
        }
        for (int i = 0; i < n; i++) {
            int x = order[i];
            if (a[x].pos < 0 || a[x].pos > L) {
                cout << "Fell off" << endl;
            } else {
                cout << a[x].pos;
                if (a[x].fangxiang == "turn") cout << " Turning" << endl;
                else cout << " " << a[x].fangxiang << endl;

            }
        }
        cout << endl;
    }
    return 0;
}

/*
Sample Input
2
10 1 4
1 R
5 R
3 L
10 R
10 2 3
4 R
5 L
8 R
 */

/*
Sample Output
Case #1:
2 Turning
6 R
2 Turning
Fell off
Case #2:
3 L
6 R
10 R
 */