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
int du[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;

            add(x, y);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) tarjan(i);
    }
}