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
    int y, nxt;
} g[maxm * 2];
int head[maxn];
void add(int x, int y) {
    ++etot;
    g[etot].y = y;
    g[etot].nxt = head[x];
    head[x] = etot;
}

int idx = 0, cutot;
int dfn[maxn], low[maxn], cut[maxn];
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
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (qc[{x, y}] == 0) {
            add(x, y);
            qc[{x, y}] = 1;
        }
        if (qc[{y, x}] == 0) {
            add(y, x);
            qc[{y, x}] = 1;
        }
    }
    cutot = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);
    cout << cutot << "\n";
    for (int i = 1; i <= n; i++)
        if (cut[i]) cout << i << " ";
}
