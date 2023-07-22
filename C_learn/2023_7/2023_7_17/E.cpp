#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
int n, m;
int idx = 0, sccnt = 0, top = 0;
int dfn[maxn], low[maxn], du[maxn], all[maxn], id[maxn];
bool scc[maxn];
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
stack<int> s;
void tarjan(int x) {
    dfn[x] = low[x] = ++idx;
    scc[x] = 1;
    s.push(x);
    for (int i = head[x]; i; i = g[i].nxt) {
        int y = g[i].y;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (scc[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        sccnt++;
        int k;
        do {
            k = s.top();
            s.pop();
            scc[k] = 0;
            id[k] = sccnt;
            all[sccnt]++;
        } while (x != k);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = g[j].nxt) {
            if (id[i] != id[g[j].y]) du[id[i]]++;
        }
    }
    int count = 0;
    for (int i = 1; i <= sccnt; i++) {
        if (!du[i]) {
            if (count) {
                cout << 0 << endl;
                return 0;
            }
            count = i;
        }
    }
    cout << all[count] << endl;
}