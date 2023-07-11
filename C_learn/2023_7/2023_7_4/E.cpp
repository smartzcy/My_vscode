// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m, ans, pre[N];
// vector<pair<int, int>> vec[N];
// void dfs(int u, int fa, int sum, int deal) {
//     for (auto &[v, w] : vec[u]) {
//         if (v == fa) continue;
//         pre[v] = u;
//         if (v == deal) {
//             ans = sum + w;
//             return;
//         }
//         dfs(v, u, sum + w, deal);
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n;
//         for (int i = 1; i < n; i++) {
//             int u, v, w;
//             cin >> u >> v >> w;
//             vec[u].push_back({v, w});
//             vec[v].push_back({u, w});
//         }
//         string str;
//         int a, b, k;
//         while (cin >> str, str != "DONE") {
//             if (str == "DIST") {
//                 cin >> a >> b;
//                 dfs(a, a, 0, b);
//                 cout << ans << endl;
//             } else {
//                 cin >> a >> b >> k;
//                 dfs(a, a, 0, b);
//                 vector<int> an;
//                 while (pre[b]) {
//                     an.push_back(pre[b]);
//                     b = pre[b];
//                 }
//                 reverse(an.begin(), an.end());
//                 cout << an[k - 1] << endl;
//             }
//         }
//     }
// }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 10010;
int head[N << 1];
int to[N << 1];
int nxt[N << 1];
int cnt = 0;
int d[N];
int f[N][31];
int road[N << 1];
int dis[N];
void add(int x, int y, int z) {
    to[cnt] = y;
    nxt[cnt] = head[x];
    road[cnt] = z;
    head[x] = cnt++;
}
void dfs(int x, int fx) {
    d[x] = d[fx] + 1;
    f[x][0] = fx;
    for (int i = 1; (1 << i) <= d[x]; i++) {
        if (f[x][i - 1] != -1) {
            f[x][i] = f[f[x][i - 1]][i - 1];
        }
    }
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int aa = to[i];
        if (aa != fx) {
            dis[aa] = dis[x] + road[i];
            dfs(aa, x);
        }
    }
}
int lca(int a, int b) {
    if (d[a] < d[b]) {
        swap(a, b);
    }
    for (int i = 30; i >= 0; i--) {
        if (d[b] <= d[a] - (1 << i)) {
            a = f[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 30; i >= 0; i--) {
        if (f[a][i] == f[b][i]) {
            continue;
        } else {
            a = f[a][i];
            b = f[b][i];
        }
    }
    return f[a][0];
}
int querylen(int a, int b, int k) {
    int tt = lca(a, b);
    int bian = 0;
    if ((d[a] - d[tt] + 1) >= k) {
        int ans = d[a] - k + 1;
        for (int i = 30; i >= 0; i--) {
            if ((1 << i) <= d[a] - ans) {
                a = f[a][i];
            }
        }
        return a;
    } else {
        int ans = d[tt] * 2 + k - d[a] - 1;
        for (int i = 30; i >= 0; i--) {
            if (d[b] - (1 << i) >= ans) {
                b = f[b][i];
            }
        }
        return b;
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(head, -1, sizeof(head));
        memset(to, 0, sizeof(to));
        memset(nxt, 0, sizeof(nxt));
        memset(d, 0, sizeof(d));
        memset(f, -1, sizeof(f));
        memset(road, 0, sizeof(road));
        memset(dis, 0, sizeof(dis));
        cnt = 0;
        int n, s = 1;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        dfs(s, 0);
        string flag;
        while (cin >> flag) {
            if (flag[1] == 'I') {
                int a, b;
                scanf("%d%d", &a, &b);
                int tt = lca(a, b);
                printf("%d\n", dis[a] + dis[b] - 2 * dis[tt]);
            }
            if (flag[1] == 'T') {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                printf("%d\n", querylen(a, b, c));
            }
            if (flag[1] == 'O')
                break;
        }
    }
    return 0;
}