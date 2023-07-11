#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m, r;
int v1[N];
vector<int> vec[N];
int par[N][20], dep[N], cnt[N], val[N], val1[N];
int Ri() {
    int x = 0, y = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') y = -1;
    for (; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + c - '0';
    return x * y;
}
long long lowbit(long long x) {
    return x & -x;
}
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    par[u][0] = fa;
    for (int i = 1; i < 20; ++i) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto &v : vec[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}
int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (dep[par[u][i]] >= dep[v]) u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i], v = par[v][i];
        }
    }
    return par[u][0];
}
void dfs1(int u, int fa) {
    val[u] = cnt[u];
    for (auto &v : vec[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        val[u] += val[v];
    }
}
void dfs2(int u, int fa) {
    val1[u] = val[u] + v1[u];
    for (auto &v : vec[u]) {
        if (v == fa) continue;
        dfs2(v, u);
        val1[u] += val1[v];
    }
}
int main() {
    n = Ri();
    m = Ri();
    r = Ri();
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    for (int i = 1, a, b; i < n; i++) {
        a = Ri();
        b = Ri();
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(r, 0);
    while (m--) {
        int k, a, b, x;
        k = Ri();
        if (k == 1) {
            a = Ri();
            b = Ri();
            x = Ri();
            cnt[a] += x;
            cnt[b] += x;
            cnt[LCA(a, b)] -= x;
            cnt[par[LCA(a, b)][0]] -= x;
        } else if (k == 2) {
            dfs1(r, 0);
            a = Ri();
            printf("%d\n", val[a] + v1[a]);
        } else if (k == 3) {
            a = Ri();
            dfs1(r, 0);
            dfs2(r, 0);
            printf("%d\n", val1[a]);
        }
    }
    return 0;
}