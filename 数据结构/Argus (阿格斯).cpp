#include "bits/stdc++.h"

using namespace std;
const int N = 1000000 + 10;

struct Item {
    int qnum, period, time;

    bool operator<(const Item &a) const {
        return time == a.time ? qnum > a.qnum : time > a.time;
    }
};

string str;

int main() {
    priority_queue <Item> q;
    while (cin >> str) {
        if (str == "#") break;
        Item item;
        cin >> item.qnum >> item.period;
        item.time = item.period;
        q.push(item);
    }
    int k;
    cin >> k;
    while (k--) {
        Item tmp = q.top();
        q.pop();
        ::printf("%d\n", tmp.qnum);
        tmp.time += tmp.period;
        q.push(tmp);
    }
}

/*
Sample Input
Register 2004 200
Register 2005 300
#
5
 */

/*
Sample Output
2004
2005
2004
2004
2005
 */