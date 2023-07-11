#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;
const int maxn = 100100;
int n;
vector<int> nums;
vector<array<int, 4>> evt;
struct info {
    int minv, cnt;
};
struct node {
    int t;
    info val;
} seg[maxn * 8];
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
void settag(int id, int t) {
    seg[id].val.minv += t;
    seg[id].t += t;
}
void up(int id) {
    seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}
void down(int id) {
    if (seg[id].t) {
        settag(id * 2, seg[id].t);
        settag(id * 2 + 1, seg[id].t);
        seg[id].t = 0;
    }
}
void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = {0, (info){0, nums[r] - nums[r - 1]}};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    up(id);
}
void modify(int id, int l, int r, int ql, int qr, int val) {
    if (ql == l && qr == r) {
        settag(id, val);
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    if (qr <= mid)
        modify(id * 2, l, mid, ql, qr, val);
    else if (ql > mid)
        modify(id * 2 + 1, mid + 1, r, ql, qr, val);
    else {
        modify(id * 2, l, mid, ql, mid, val);
        modify(id * 2 + 1, mid + 1, r, mid + 1, qr, val);
    }
    up(id);
}
int find(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, x2, y1, y2;
        // cin >> x1 >> x2 >> y1 >> y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2) continue;
        evt.push_back({x1, 1, y1, y2});
        evt.push_back({x2, -1, y1, y2});
        nums.push_back(y1);
        nums.push_back(y2);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    sort(evt.begin(), evt.end());
    int m = nums.size() - 1;
    build(1, 1, m);
    int prex = 0, len = seg[1].val.cnt; // 总长度
    ll ans = 0;
    for (auto [x, ty, l, r] : evt) {
        int cov = len;
        if (!seg[1].val.minv) cov -= seg[1].val.cnt; // 如果最小值>0，说明全都被矩形覆盖了
        ans += 1ll * (x - prex) * cov;               // 长乘宽
        l = find(l) + 1;                             // 用l+1这个点表示[l, l + 1]这段长度
        r = find(r);
        modify(1, 1, m, l, r, ty);
        prex = x;
    }
    cout << ans;
}