#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
vector<int> nums;
vector<array<int, 4>> evt;
struct info {
    int minv, cnt;
};
info operator+(const info &ls, const info &rs) {
    info rt;
    rt.minv = min(ls.minv, rs.minv);
    if (ls.minv < rs.minv)
        rt.cnt = ls.cnt;
    else if (ls.minv > rs.minv)
        rt.cnt = rs.cnt;
    else
        rt.cnt = ls.cnt + rs.cnt;
    return rt;
}
struct node {
    int t;
    info val;
} seg[N << 3];
void up(int id) {
    seg[id].val = seg[id << 1].val + seg[id << 1 | 1].val;
}
void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = {0, (info){0, nums[r] - nums[r - 1]}};
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void settag(int id, int val) {
    seg[id].val.minv += val;
    seg[id].t += val;
}
void down(int id) {
    if (seg[id].t) {
        settag(id << 1, seg[id].t);
        settag(id << 1 | 1, seg[id].t);
        seg[id].t = 0;
    }
}
void modify(int id, int l, int r, int ql, int qr, int val) {
    if (ql == l && qr == r) {
        settag(id, val);
        return;
    }
    down(id);
    int mid = l + r >> 1;
    if (qr <= mid)
        modify(id << 1, l, mid, ql, qr, val);
    else if (ql > mid)
        modify(id << 1 | 1, mid + 1, r, ql, qr, val);
    else {
        modify(id << 1, l, mid, ql, mid, val);
        modify(id << 1 | 1, mid + 1, r, mid + 1, qr, val);
    }
    up(id);
}
int find(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2) continue;
        evt.push_back({y1, 1, x1, x2});
        evt.push_back({y2, -1, x1, x2});
        nums.push_back(x1);
        nums.push_back(x2);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    sort(evt.begin(), evt.end());
    int m = nums.size() - 1;
    build(1, 1, m);
    int prey = 0, len = seg[1].val.cnt;
    long long ans = 0;
    for (auto &[y, tx, l, r] : evt) {
        int cov = len;
        if (!seg[1].val.minv) cov -= seg[1].val.cnt;
        ans += 1ll * (y - prey) * cov;
        l = find(l) + 1;
        r = find(r);
        modify(1, 1, m, l, r, tx);
        prey = y;
    }
    cout << ans << endl;
}