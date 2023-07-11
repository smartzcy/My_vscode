#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
const int lim = 1e6;
int n, m;
vector<pair<int, int>> vec[N];
vector<int> vec1[N], vec2[N];
struct node {
    int l, r;
    int val;
} seg[N << 2];
void up(int id) {
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].val = 0;
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void add(int id, int pos, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (l == r) {
        seg[id].val += val;
        return;
    }
    int mid = l + r >> 1;
    if (mid >= pos)
        add(id << 1, pos, val);
    else
        add(id << 1 | 1, pos, val);
    up(id);
}
int query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql <= l && r <= qr) return seg[id].val;
    int mid = l + r >> 1, ans = 0;
    if (ql <= mid) ans += query(id << 1, ql, qr);
    if (qr > mid) ans += query(id << 1 | 1, ql, qr);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        vec1[lx].push_back(y);
        vec2[rx].push_back(y);
        if (rx == lim && lx == 0) ans++;
    }
    for (int i = 1; i <= m; i++) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        vec[x].push_back({ly, ry});
        if (ly == 0 && ry == lim) ans++;
    }
    build(1, 1, lim + 1);
    for (int i = 0; i <= lim; i++) {
        for (auto &y : vec1[i]) {
            add(1, y + 1, 1);
        }
        for (auto &q : vec[i]) {
            ans += query(1, q.first + 1, q.second + 1);
        }
        for (auto &y : vec2[i]) {
            add(1, y + 1, -1);
        }
    }
    cout << ans << endl;
}