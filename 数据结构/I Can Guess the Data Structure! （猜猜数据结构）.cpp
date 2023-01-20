#include "bits/stdc++.h"

using namespace std;
int a[1005][2];
int n;
int is_q, is_priorityq, is_s;
int flag;

void is_queue() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 1) {
            q.push(a[i][1]);
        } else {
            if (q.empty()) return;
            int x = q.front();
            q.pop();
            if (x != a[i][1]) return;
        }
    }
    is_q = 1;
    flag++;
}

void is_stack() {
    stack<int> stack;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 1) {
            stack.push(a[i][1]);
        } else {
            if (stack.empty()) return;
            int x = stack.top();
            stack.pop();
            if (x != a[i][1]) return;
        }
    }
    is_s = 1;
    flag++;
}

void is_priority_queue() {
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 1) {
            q.push(a[i][1]);
        } else {
            if (q.empty()) return;
            int x = q.top();
            q.pop();
            if (x != a[i][1]) return;
        }
    }
    is_priorityq = 1;
    flag++;
}

int main() {
    while (::scanf("%d", &n) == 1) {

        is_q = 0, is_s = 0, is_priorityq = 0;
        flag = 0;
        for (int i = 0; i < n; i++) {
            ::scanf("%d%d", &a[i][0], &a[i][1]);
        }
        is_queue();
        is_stack();
        is_priority_queue();
        if (flag == 0) ::printf("impossible\n");
        else if (flag > 1) ::printf("not sure\n");
        else if (is_q) ::printf("queue\n");
        else if (is_priorityq) ::printf("priority queue\n");
        else if (is_s) ::printf("stack\n");
    }
}

/*
Sample Input
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4
 */

/*
Sample Output
queue
not sure
impossible
stack
priority queue
 */