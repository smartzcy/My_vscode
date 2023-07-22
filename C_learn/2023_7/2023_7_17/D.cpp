#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m;
int etot = 1;
struct node {
    int y, nxt;
} g[N * 2];
int head[N * 2];
void add(int x, int y) {
    g[++etot].y = y;
    g[etot].nxt = head[x];
    head[x] = etot;
}
int idx = 0, cutot;
int dfn[N], low[N], cut[N];
void tarjan(int x, int fa) {
    int child = 0;
    dfn[x] = low[x] = ++idx;
    for (int i = head[x]; i; i = g[i].nxt) {
        int y = g[i].y;
        if (!dfn[y]) {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x] && x != fa) cut[x] = 1;
            if (x == fa) child++;
        } else
            low[x] = min(low[x], dfn[y]);
    }
    if (child >= 2 && x == fa) cut[x] = 1;
    cutot += cut[x];
}
map<pair<int, int>, bool> qc;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        if (qc[{x, y}] == 0) add(x, y), qc[{x, y}] = 1;
        if (qc[{y, x}] == 0) add(y, x), qc[{y, x}] = 1;
    }
    cutot = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);
    cout << cutot << endl;
    for (int i = 1; i <= n; i++)
        if (cut[i]) cout << i << " ";
}