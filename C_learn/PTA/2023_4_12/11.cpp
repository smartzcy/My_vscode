#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, in[50], pre[50], t = 1;
struct node {
    int w;
    int left;
    int right;
};
node T[10000];
void create(int left, int right, int n) {
    if (left >= right) return;
    T[n].w = pre[t];
    T[n].left = 2 * n;
    T[n].right = 2 * n + 1;
    int i, mid = 0;
    for (i = left; i <= right - 1; i++) {
        if (pre[t] == in[i]) {
            mid = i;
            break;
        }
    }
    t++;
    if (mid == 0) return;
    create(left, mid, 2 * n);
    create(mid + 1, right, 2 * n + 1);
}
void BFS() {
    queue<node> q;
    q.push(T[1]);
    node f;
    while (!q.empty()) {
        f = q.front();
        q.pop();
        if (T[f.right].w != 0)
            q.push(T[f.right]);
        if (T[f.left].w != 0)
            q.push(T[f.left]);
        if (!q.empty())
            printf("%d ", f.w);
        else
            printf("%d", f.w);
    }
}
int main() {
    int i;
    cin >> N;
    for (i = 1; i <= N; i++)
        cin >> in[i];
    for (i = 1; i <= N; i++)
        cin >> pre[i];
    create(1, N + 1, 1);
    BFS();
    return 0;
}
