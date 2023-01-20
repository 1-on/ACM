#include "bits/stdc++.h"

using namespace std;
const int maxn = 800;


struct Item {
    int s, b;

    Item(int s, int b) : s(s), b(b) {}

    bool operator<(const Item &rhs) const {
        return s > rhs.s;
    }
};

void mymerge(int a[], int b[], int c[], int n) {
    priority_queue <Item> q;
    for (int i = 0; i < n; i++) {
        q.push(Item(a[i] + b[0], 0));
    }
    for (int i = 0; i < n; i++) {
        Item item = q.top();
        q.pop();
        c[i] = item.s;

        q.push(Item(item.s - b[item.b] + b[item.b + 1], item.b + 1));


    }
}

int a[maxn][maxn];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
            sort(a[i], a[i] + n);
        }
        for (int i = 1; i < n; i++) {
            mymerge(a[0], a[i], a[0], n);
        }
        for (int i = 0; i < n - 1; i++) {
            cout << a[0][i] << " ";
        }
        cout << a[0][n - 1] << endl;
    }
}

/*
Sample Input
3
1 8 5
9 2 5
10 7 6
2
1 1
1 2
 */

/*
Sample Output
9 10 12
2 2
 */