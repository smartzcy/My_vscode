#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
typedef long long ll;
int n, m;
int etot = 1;
struct edge {
    int y, nxt, id;
} g[maxm * 2];
int head[maxm * 2];
void add(int x, int y, int z) {
    ++etot;
    g[etot].y = y;
    g[etot].nxt = head[x];
    g[etot].id = z;
    head[x] = etot;
}
int idx = 0;
int dfn[maxn], low[maxn];
vector<long long> BRIDGE;
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++idx;
    for (int i = head[x]; i; i = g[i].nxt) {
        int y = g[i].y;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                BRIDGE.push_back(g[i].id);
            }
        } else if (i != (in_edge ^ 1))
            low[x] = min(low[x], low[y]);
    }
}
int main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y, i);
        add(y, x, i);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);
    sort(BRIDGE.begin(), BRIDGE.end());
    cout << BRIDGE.size() << "\n";
    //    for (int i=0; i<BRIDGE.size(); i++) cout << BRIDGE[i] << " ";
}
