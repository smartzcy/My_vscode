// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int INF = 1e9;
// const int N = 2e5 + 100;
// int n, q, tot, mx;
// int a[N], rt[N];
// int ls[N * 100], rs[N * 100], sum[N * 100];
// void change(int &rt, int pre, int l, int r, int pos) {
//     rt = ++tot;
//     ls[rt] = ls[pre], rs[rt] = rs[pre], sum[rt] = sum[pre] + 1;
//     if (l == r)
//         return;
//     int mid = l + r >> 1;
//     if (pos <= mid)
//         change(ls[rt], ls[pre], l, mid, pos);
//     else
//         change(rs[rt], rs[pre], mid + 1, r, pos);
// }
// int query(int rt1, int rt2, int pre, int l, int r, int k) {
//     if (l == r) return l;
//     int cnt = sum[ls[rt1]] - sum[ls[pre]] + sum[ls[rt2]] - sum[ls[pre]];
//     int mid = l + r >> 1;
//     if (cnt >= k) return query(ls[rt1], ls[rt2], ls[pre], l, mid, k);
//     return query(rs[rt1], ls[rt2], rs[pre], mid + 1, r, k - cnt);
// }
// int query(int rt, int pre, int l, int r, int k) {
//     if (l == r) return l;
//     int cnt = sum[ls[rt]] - sum[ls[pre]];
//     int mid = l + r >> 1;
//     if (cnt >= k) return query(ls[rt], ls[pre], l, mid, k);
//     return query(rs[rt], rs[pre], mid + 1, r, k - cnt);
// }
// // int par[N][20], dep[N];
// // vector<pair<int, int>> G[N];
// // void dfs(int u, int fa) {
// //     dep[u] = dep[fa] + 1;
// //     par[u][0] = fa;
// //     for (int i = 1; i < 20; ++i) {
// //         par[u][i] = par[par[u][i - 1]][i - 1];
// //     }
// //     for (auto &[v, w] : G[u]) {
// //         if (v == fa) continue;
// //         change(rt[v], rt[u], 1, mx, w);
// //         dfs(v, u);
// //     }
// // }
// // int getLca(int u, int v) {
// //     if (dep[u] < dep[v]) swap(u, v);
// //     for (int i = 19; i >= 0; --i) {
// //         if (dep[par[u][i]] >= dep[v]) u = par[u][i];
// //     }
// //     if (u == v) return u;
// //     for (int i = 19; i >= 0; --i) {
// //         if (par[u][i] != par[v][i]) {
// //             u = par[u][i], v = par[v][i];
// //         }
// //     }
// //     return par[u][0];
// // }
// struct yyy {
//     int t, nex, val;
// } e[2 * 500001];
// int dep[500001], fa[500001][22], lg[500001], head[500001];
// int nu;
// void add(int x, int y, int val) {
//     e[++nu].t = y;
//     e[nu].nex = head[x];
//     e[nu].val = val;
//     head[x] = nu;
// }
// void dfs(int f, int fath) {
//     dep[f] = dep[fath] + 1;
//     fa[f][0] = fath;
//     for (int i = 1; (1 << i) <= dep[f]; i++)
//         fa[f][i] = fa[fa[f][i - 1]][i - 1];
//     for (int i = head[f]; i; i = e[i].nex)
//         if (e[i].t != fath) {
//             change(rt[e[i].t], rt[f], 1, mx, e[i].val);
//             dfs(e[i].t, f);
//         }
// }
// int lca(int x, int y) {
//     if (dep[x] < dep[y])
//         swap(x, y);
//     while (dep[x] > dep[y])
//         x = fa[x][lg[dep[x] - dep[y]] - 1];
//     if (x == y)
//         return x;
//     for (int k = lg[dep[x]] - 1; k >= 0; k--)
//         if (fa[x][k] != fa[y][k])
//             x = fa[x][k], y = fa[y][k];
//     return fa[x][0];
// }
// void Init(int n) {
//     for (int i = 1; i <= n; i++) {
//         head[i] = 0;
//         dep[i] = 0;
//     }
//     for (int i = 1; i <= N; i++) sum[i] = 0;
//     mx = 0;
//     tot = 0;
// }
// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         scanf("%d", &n);
//         Init(n);
//         for (int i = 1, u, v, w; i < n; i++) {
//             scanf("%d %d %d", &u, &v, &w);
//             // G[u].push_back({v, w});
//             // G[v].push_back({u, w});
//             add(u, v, w);
//             add(v, u, w);
//             mx = max(mx, w);
//         }
//         dfs(1, 0);
//         for (int i = 1; i <= n; i++) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//         scanf("%d", &q);
//         while (q--) {
//             int a, b;
//             scanf("%d %d", &a, &b);
//             int lca1 = lca(a, b);
//             if (lca1 == a || lca1 == b) {
//                 if (a == lca1) a = b;
//                 int k = dep[a] - dep[lca1];
//                 if (k % 2) {
//                     printf("%.1f\n", query(rt[a], rt[lca1], 1, mx, (k + 1) / 2) * 1.0);
//                 } else {
//                     printf("%.1f\n", (query(rt[a], rt[lca1], 1, mx, k / 2) + query(rt[a], rt[lca1], 1, mx, k / 2 + 1)) / 2.0);
//                 }
//             } else {
//                 int k = dep[a] - dep[lca1] + dep[b] - dep[lca1];
//                 if (k % 2) {
//                     printf("%.1f\n", query(rt[a], rt[b], rt[lca1], 1, mx, (k + 1) / 2) * 1.0);
//                 } else {
//                     printf("%.1f\n", (query(rt[a], rt[b], rt[lca1], 1, mx, k / 2) + query(rt[a], rt[b], rt[lca1], 1, mx, k / 2 + 1)) / 2.0);
//                 }
//             }
//         }
//     }
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 9;
int n, q, mx;
int head[N], to[N << 1], val[N << 1], nex[N << 1], now;
void add(int a, int b, int v) {
    nex[++now] = head[a];
    head[a] = now;
    to[now] = b;
    val[now] = v;
}
int rt[N], sum[N * 40], ls[N * 40], rs[N * 40], cnt;
void change(int pre, int rt, int l, int r, int p) {
    sum[rt] = sum[pre] + 1;
    ls[rt] = ls[pre];
    rs[rt] = rs[pre];
    if (l == r) return;
    int mid = (l + r) / 2;
    if (p <= mid)
        change(ls[pre], ls[rt] = ++cnt, l, mid, p);
    else
        change(rs[pre], rs[rt] = ++cnt, mid + 1, r, p);
}
int query(int pre, int rt, int l, int r, int k) {
    if (l == r) return l;
    int cnt = sum[ls[rt]] - sum[ls[pre]];
    int mid = (l + r) / 2;
    if (k > cnt) return query(rs[pre], rs[rt], mid + 1, r, k - cnt);
    return query(ls[pre], ls[rt], l, mid, k);
}
double query(int pre, int rt1, int rt2, int l, int r, int k) {
    if (l == r) return l;
    int cnt = sum[ls[rt1]] - sum[ls[pre]] + sum[ls[rt2]] - sum[ls[pre]];
    int mid = (l + r) / 2;
    if (cnt < k) return query(rs[pre], rs[rt1], rs[rt2], mid + 1, r, k - cnt);
    return query(ls[pre], ls[rt1], ls[rt2], l, mid, k);
}
int p[N][30], dep[N];
void ST(int n) {
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
}
int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int i;
    for (i = 0; (1 << i) < dep[b]; i++)
        ;
    i--;
    for (;;) {
        if (dep[a] == dep[b]) break;
        if (dep[b] - dep[a] < (1 << i))
            i--;
        else
            b = p[b][i];
    }
    for (i = 0; (1 << i) < dep[b]; i++)
        ;
    i--;
    for (;;) {
        if (a == b) return a;
        if (p[a][0] == p[b][0]) return p[a][0];
        if (p[a][i] == p[b][i])
            i--;
        else
            a = p[a][i], b = p[b][i];
    }
}
void dfs(int _p, int fa, int deep) {
    p[_p][0] = fa;
    dep[_p] = deep;
    for (int i = head[_p]; i; i = nex[i]) {
        int u = to[i];
        if (u == fa) continue;
        change(rt[_p], rt[u] = ++cnt, 1, mx, val[i]);
        dfs(u, _p, deep + 1);
    }
}
void init() {
    memset(head, 0, sizeof head);
    now = 0;
    cnt = 0;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n - 1; i++) {
            int a, b, v;
            scanf("%d%d%d", &a, &b, &v);
            add(a, b, v);
            add(b, a, v);
            mx = max(mx, v);
        }
        rt[1] = 0;
        dfs(1, 0, 1);
        ST(n);
        scanf("%d", &q);
        while (q--) {
            int a, b, F;
            scanf("%d%d", &a, &b);
            F = lca(a, b);
            if (F == a || F == b) {
                if (a == F) a = b;
                int k = dep[a] - dep[F];
                if (k % 2) {
                    printf("%.1f\n", 1.0 * query(rt[F], rt[a], 1, mx, (k + 1) / 2));
                } else {
                    double ans = 1.0 * query(rt[F], rt[a], 1, mx, k / 2) + query(rt[F], rt[a], 1, mx, k / 2 + 1);
                    ans /= 2;
                    printf("%.1f\n", ans);
                }
            } else {
                int k = dep[a] - dep[F] + dep[b] - dep[F];
                if (k % 2) {
                    printf("%.1f\n", 1.0 * query(rt[F], rt[a], rt[b], 1, mx, (k + 1) / 2));
                } else {
                    double ans = 1.0 * query(rt[F], rt[a], rt[b], 1, mx, k / 2) + query(rt[F], rt[a], rt[b], 1, mx, k / 2 + 1);
                    ans /= 2;
                    printf("%.1f\n", ans);
                }
            }
        }
    }
}
