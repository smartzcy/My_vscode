#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6 + 7;
vector<int> g[N];
int num[N], val[N], ide[N];
int n, m, r;
int L[N], R[N], tot;
struct node {
    long long l, r, val;
} seg[N << 2];
void up(int id) {
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}
void build(int u, int l, int r) {
    seg[u].l = l;
    seg[u].r = r;
    if (l == r) {
        seg[u].val = num[ide[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    seg[u].val = seg[u << 1].val + seg[u << 1 | 1].val;
}
long long query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql <= l && r <= qr) return seg[id].val;
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(id << 1, ql, qr);
    else if (ql > mid)
        return query(id << 1 | 1, ql, qr);
    else
        return query(id << 1 | 1, ql, qr) + query(id << 1, ql, qr);
}
void change(int id, int pos, int val) {
    if (seg[id].l == seg[id].r) {
        seg[id].val += val;
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (pos <= mid)
        change(id << 1, pos, val);
    else
        change(id << 1 | 1, pos, val);
    up(id);
}
void dfs(int u, int fa) {
    L[u] = ++tot;
    ide[tot] = u;
    for (auto &v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    R[u] = tot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r, 0);
    build(1, 1, n);
    while (m--) {
        int k, a, x;
        cin >> k >> a;
        if (k == 1) {
            cin >> x;
            change(1, L[a], x);
        } else {
            cout << query(1, L[a], R[a]) << endl;
        }
    }
}