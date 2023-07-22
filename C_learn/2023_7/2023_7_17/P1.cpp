#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
typedef long long ll;
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
set<pair<int, int>> qc;
vector<ll> G[maxn];
ll a[maxn], v[maxn], du[maxn], ans[maxn];
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back({x, y});
        add(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++) v[scc[i]] += a[i];
    for (int i = 0; i < e.size(); i++) {
        int x = e[i].first, y = e[i].second;
        x = scc[x];
        y = scc[y];
        if (x == y || x == 0 || y == 0) continue;
        if (qc.count({x, y}) == 0) {
            qc.insert({x, y});
            G[x].push_back(y);
            du[y]++;
        }
    }
    queue<ll> q;
    for (int i = 1; i <= sccnt; i++) {
        if (du[i] == 0) {
            q.push(i);
            ans[i] = v[i];
        }
    }
    while (q.size()) {
        ll x = q.front();
        q.pop();
        for (int y : G[x]) {
            ans[y] = max(ans[x] + v[y], ans[y]);
            du[y]--;
            if (!du[y]) q.push(y);
        }
    }
    ll mx = 0;
    for (int i = 1; i <= sccnt; i++) mx = max(mx, ans[i]);
    cout << mx << "\n";
}
