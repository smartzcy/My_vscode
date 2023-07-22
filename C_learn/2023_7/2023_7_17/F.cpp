// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include <queue>
// #include <stack>
// #include <cstring>
// using namespace std;
// const int INF = 1e9;
// const int N = 5e5 + 10;
// int n, m, tot, idx, sccnt, top, ans;
// int a[N], x[N], y[N];
// int dfn[N], low[N], head[N], scc[N], sta[N], id[N], all[N];
// struct node {
//     int y, nxt;
// } g[N];
// void add(int x, int y) {
//     tot++;
//     g[tot].y = y;
//     g[tot].nxt = head[x];
//     head[x] = tot;
// }
// stack<int> s;
// void tarjan(int x) {
//     dfn[x] = low[x] = ++idx;
//     scc[x] = 1;
//     s.push(x);
//     for (int i = head[x]; i; i = g[i].nxt) {
//         int y = g[i].y;
//         if (!dfn[y]) {
//             tarjan(y);
//             low[x] = min(low[x], low[y]);
//         } else if (scc[y])
//             low[x] = min(low[x], dfn[y]);
//     }
//     if (dfn[x] == low[x]) {
//         sccnt++;
//         int k;
//         do {
//             k = s.top();
//             s.pop();
//             scc[k] = 0;
//             id[k] = sccnt;
//             all[sccnt] += a[k];
//         } while (x != k);
//     }
// }
// int vis[N], d[N];
// vector<pair<int, int>> adj[N];
// void spfa(int st) {
//     for (int i = 1; i <= n; i++)
//         d[i] = INF;
//     d[st] = 0;
//     queue<int> que;
//     que.push(st);
//     memset(vis, 0, sizeof vis);
//     vis[st] = 1;
//     while (que.size()) {
//         int u = que.front();
//         que.pop();
//         vis[u] = 0;
//         for (auto &[v, w] : adj[u]) {
//             if (d[v] > d[u] + w) {
//                 d[v] = d[u] + w;
//                 if (!vis[v]) {
//                     que.push(v);
//                     vis[v] = 1;
//                 }
//             }
//         }
//     }
// }

// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) {
//         cin >> x[i] >> y[i];
//         add(x[i], y[i]);
//     }
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) {
//         if (!dfn[i]) tarjan(i);
//     }
//     for (int i = 1; i <= m; i++) {
//         if (id[x[i]] != id[y[i]]) adj[id[x[i]]].push_back({id[y[i]], (all[id[y[i]]])});
//     }
//     int s, p;
//     cin >> s >> p;
//     spfa(s);
//     for (int i = 1; i <= p; i++) {
//         int jiu;
//         cin >> jiu;
//         // cout << id[jiu] << " " << d[id[jiu]] << endl;
//         if (d[id[jiu]] > ans) ans = d[id[jiu]];
//     }
//     cout << ans << endl;
// }

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int N = 5e5 + 10;
struct ss {
    int next, to, val;
} dat[N];
int head[N], qe[N], used[N], dis[N], color[N], sum[N];
int n, m, p, q, timeclock, ans, tot, top, S, s, t, P, jiu;
int x[N], y[N], dfn[N], low[N], instack[N], stack[N], money[N];
void add(int a, int b) {
    dat[++p].to = b;
    dat[p].next = head[a];
    head[a] = p;
}
void Add(int a, int b, int c) {
    dat[++p].to = b;
    dat[p].next = head[a];
    dat[p].val = c;
    head[a] = p;
}
void tarjan(int a) {
    dfn[a] = low[a] = ++timeclock;
    instack[a] = 1;
    stack[++top] = a;
    for (int i = head[a]; i; i = dat[i].next) {
        int v = dat[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[a] = min(low[a], low[v]);
        } else if (instack[v])
            low[a] = min(low[a], dfn[v]);
    }
    if (dfn[a] == low[a]) {
        tot++;
        while (stack[top + 1] != a) {
            color[stack[top]] = tot;
            sum[tot] += money[stack[top]];
            instack[stack[top--]] = 0;
        }
    }
}
void spfa() {
    for (int i = 1; i <= tot; i++)
        dis[i] = 0x7fffffff;
    int ts = color[S];
    dis[ts] = -sum[ts];
    qe[0] = ts;
    p = q = 0;
    while (p <= q) {
        s = qe[p % n];
        used[s] = 0;
        t = head[s];
        while (t) {
            if (dis[s] + dat[t].val < dis[dat[t].to]) {
                dis[dat[t].to] = dis[s] + dat[t].val;
                if (!used[dat[t].to]) {
                    qe[++q % n] = dat[t].to;
                    used[dat[t].to] = 1;
                }
            }
            t = dat[t].next;
        }
        p++;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        add(x[i], y[i]);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &money[i]);
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) {
            tarjan(i);
        }
    memset(dat, 0, sizeof(dat));
    memset(head, 0, sizeof(head));
    p = 0;
    for (int i = 1; i <= m; i++) {
        if (color[x[i]] != color[y[i]])
            Add(color[x[i]], color[y[i]], -(sum[color[y[i]]]));
    }
    scanf("%d", &S);
    spfa();
    scanf("%d", &P);
    for (int i = 1; i <= P; i++) {
        scanf("%d", &jiu);
        if (-dis[color[jiu]] > ans)
            ans = -dis[color[jiu]];
    }
    printf("%d\n", ans);
    return 0;
}