#include "bits/stdc++.h"

using namespace std;
const int N = 25;
int n;
int A[30];
map<int, int> table;
string s;

int bitcount(int x) {
    return x == 0 ? 0 : bitcount(x / 2) + (x & 1);
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> s;
            A[i] = 0;
            for (int j = 0; j < s.length(); j++) {
                A[i] ^= (1 << (s[j] - 'A'));
            }
        }
        table.clear();
        int n1 = n / 2, n2 = n - n1;
        for (int i = 0; i < (1 << n1); i++) {
            int x = 0;
            for (int j = 0; j < n1; j++) {
                if (i & (1 << j)) x ^= A[j];
            }
            if (!table.count(x) || bitcount(table[x]) < bitcount(i)) table[x] = i;
        }
        int ans = 0;
        for (int i = 0; i < (1 << n2); i++) {
            int x = 0;
            for (int j = 0; j < n2; j++) {
                if (i & (1 << j)) x ^= A[j + n1];
            }
            if (table.count(x) && bitcount(ans) < bitcount(i) + bitcount(table[x]))
                ans = (i << n1) ^ table[x];
        }
        printf("%d\n", bitcount(ans));
        for (int i = 0; i < n; i++)
            if (ans & (1 << i)) printf("%d ", i + 1);
        puts("");
    }
}

/*
Sample Input
1
ABC
6
ABD
EG
GE
ABE
AC
BCD
 */

/*
Sample Output
0
5
1 2 3 5 6
 */