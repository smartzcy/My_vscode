#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
int n, m;
int idx = 0, sccnt = 0, top = 0;
vector<pair<int, int>> e;
int dfn[maxn], low[maxn], scc[maxn], sta[maxn];
int etot = 0;
struct edge {
    int y, nxt;
} g[maxm];
int head[maxn];
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
        while (sta[top] != x) {
            scc[sta[top]] = sccnt;
            top--;
        }
        scc[sta[top]] = sccnt;
        top--;
    }
}
void init(int n) {
    for (int i = 0; i <= (n + 1) * 2; i++) {
        g[i].y = 0;
        g[i].nxt = 0;
        head[i] = 0;
        dfn[i] = 0;
        low[i] = 0;
        scc[i] = 0;
        sta[i] = 0;
    }
    etot = 0;
    idx = 0;
    sccnt = 0;
    top = 0;
}
map<pair<int, int>, int> mpf;
void solve() {
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        char sx, sy;
        int x, y;
        cin >> sx >> x >> sy >> y;
        x--;
        y--;
        x = x * 2 + (sx == 'h');
        y = y * 2 + (sy == 'h');
        add(x ^ 1, y);
        add(y ^ 1, x);
    }
    for (int i = 0; i < 2 * n; i++)
        if (!dfn[i]) tarjan(i);
    long long cntans = 0;
    for (int i = 0; i < n; i++)
        if (scc[i * 2] == scc[i * 2 + 1]) {
            cout << "BAD\n";
            return;
        }
    cout << "GOOD\n";
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
