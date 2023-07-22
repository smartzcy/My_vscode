#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
struct node {
    int y, nxt;
} g[N];
int idx, top, sccnt;
int head[N], etot, dfn[N], low[N], sta[N], scc[N];
void add(int x, int y) {
    g[++etot].y = y;
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
        } else if (!scc[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        sccnt++;
        while (sta[top] != x) {
            scc[sta[top--]] = sccnt;
        }
        scc[sta[top--]] = sccnt;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char a, b;
        int x, y;
        cin >> a >> x >> b >> y;
    }
}