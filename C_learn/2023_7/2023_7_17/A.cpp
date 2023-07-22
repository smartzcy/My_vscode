#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, a[N], etot = 0, idx, top, sccnt;
int dfn[N], low[N], scc[N], sta[N], head[N];
vector<pair<int, int>> e;
struct node {
    int y;
    int nxt;
} g[N];
vector<int> G[N];
void add(int x, int y) {
    ++etot;
    g[etot].y = y;
    g[etot].nxt = head[x];
    head[x] = etot;
}
void tarjan(int x) {
    dfn[x] = low[x] = ++idx;
    sta[++top] = x;
    for (int i = head[x]; i; i = g[i].nxt) {
        int y = g[i].y;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (!scc[y])
            low[x] = min(low[x], low[y]);
    }
    if (dfn[x] == low[x]) {
        sccnt++;
        while (sta[top] != x) scc[sta[top--]] = sccnt;
        scc[sta[top--]] = sccnt;
    }
}
set<pair<int, int>> qc;
int du[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        e.push_back({x, y});
        add(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++) g[i].y = 0, g[i].nxt = 0;
    for (int i = 0; i <= etot + 2; i++) head[i] = 0;
    etot = 0;
    for (int i = 0; i < e.size(); i++) {
        int x = e[i].first, y = e[i].second;
        x = scc[x], y = scc[y];
        if (x == y || x == 0 || y == 0) continue;
        if (qc.count({x, y}) == 0) add(x, y), qc.insert({x, y}), G[x].push_back(y), du[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= sccnt; i++) {
        if (du[i])
            ;
    }
}