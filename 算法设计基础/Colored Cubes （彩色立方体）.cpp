#include "bits/stdc++.h"

using namespace std;

int dice24[24][6] = {
        {2, 1, 5, 0, 4, 3},
        {2, 0, 1, 4, 5, 3},
        {2, 4, 0, 5, 1, 3},
        {2, 5, 4, 1, 0, 3},
        {4, 2, 5, 0, 3, 1},
        {5, 2, 1, 4, 3, 0},
        {1, 2, 0, 5, 3, 4},
        {0, 2, 4, 1, 3, 5},
        {0, 1, 2, 3, 4, 5},
        {4, 0, 2, 3, 5, 1},
        {5, 4, 2, 3, 1, 0},
        {1, 5, 2, 3, 0, 4},
        {5, 1, 3, 2, 4, 0},
        {1, 0, 3, 2, 5, 4},
        {0, 4, 3, 2, 1, 5},
        {4, 5, 3, 2, 0, 1},
        {1, 3, 5, 0, 2, 4},
        {0, 3, 1, 4, 2, 5},
        {4, 3, 0, 5, 2, 1},
        {5, 3, 4, 1, 2, 0},
        {3, 4, 5, 0, 1, 2},
        {3, 5, 1, 4, 0, 2},
        {3, 1, 0, 5, 4, 2},
        {3, 0, 4, 1, 5, 2},
};
int n;
vector <string> names;
map<string, int> map1;
int dice[5][6];
int r[5], color[5][6];
int ans;

int ID(string str) {
    if (map1.count(str)) return map1[str];
    names.push_back(str);
    return map1[str] = names.size() - 1;
}

void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            color[i][dice24[r[i]][j]] = dice[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int cnt[24];
        memset(cnt, 0, sizeof(cnt));
        int MAX = 0;
        for (int j = 0; j < n; j++) {
            MAX = max(MAX, ++cnt[color[j][i]]);
        }
        sum += n - MAX;
    }
    ans = min(ans, sum);
}

void dfs(int d) {
    if (d == n) check();
    else {
        for (int i = 0; i < 24; i++) {
            r[d] = i;
            dfs(d + 1);
        }
    }
}

int main() {
    while (cin >> n && n) {
        names.clear();
        map1.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                string name;
                cin >> name;
                dice[i][j] = ID(name);
            }
        }
        ans = n * 6;
        r[0] = 0;
        dfs(1);
        cout << ans << endl;
    }
}

/*
Sample Input
3
scarlet green blue yellow magenta cyan
blue pink green magenta cyan lemon
purple red blue yellow cyan green
2
red green blue yellow magenta cyan
cyan green blue yellow magenta red
2
red green gray gray magenta cyan
cyan green gray gray magenta red
2
red green blue yellow magenta cyan
magenta red blue yellow cyan green
3
red green blue yellow magenta cyan
cyan green blue yellow magenta red
magenta red blue yellow cyan green
3
blue green green green green blue
green blue blue green green green
green green green green green sea-green
3
red yellow red yellow red yellow
red red yellow yellow red yellow
red red red red red red
4
violet violet salmon salmon salmon salmon
violet salmon salmon salmon salmon violet
violet violet salmon salmon violet violet
violet violet violet violet salmon salmon
1
red green blue yellow magenta cyan
4
magenta pink red scarlet vermilion wine-red
aquamarine blue cyan indigo sky-blue turquoise-blue
blond cream chrome-yellow lemon olive yellow
chrome-green emerald-green green olive vilidian sky-blue
0
 */

/*
Sample Output
4
2
0
0
2
3
4
4
0
16
 */