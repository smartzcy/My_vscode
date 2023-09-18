#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define int long long
using namespace std;
const int INF = 1e15;
const int N = 1e6 + 10;
int n, m;
int a[N];
struct node {
    int l, r;
    int cnt1, cnt2;
    int sum1, mn, tag;
    int sum2, add, mul;
} seg[N];
void up(int id) {
    seg[id].sum1 = seg[id << 1].sum1 + seg[id << 1 | 1].sum1;
    seg[id].cnt1 = seg[id << 1].cnt1 + seg[id << 1 | 1].cnt1;
    seg[id].sum2 = seg[id << 1].sum2 + seg[id << 1 | 1].sum2;
    seg[id].cnt2 = seg[id << 1].cnt2 + seg[id << 1 | 1].cnt2;
    seg[id].mn = min(seg[id << 1].mn, seg[id << 1 | 1].mn);
}
void mul(int id, int mu) {
    seg[id].sum2 *= mu;
    seg[id].mul *= mu;
    seg[id].add *= mu;
}
void add(int id, int ad) {
    seg[id].sum2 += ad * seg[id].cnt2;
    seg[id].add += ad;
}
void tag(int id, int ta) {
    seg[id].sum1 += seg[id].cnt1 * ta;
    seg[id].mn += ta;
    seg[id].tag += ta;
}
void down(int id) {
    if (1 != seg[id].mul) {
        mul(id << 1, seg[id].mul);
        mul(id << 1 | 1, seg[id].mul);
        seg[id].mul = 1;
    }
    if (seg[id].add) {
        add(id << 1, seg[id].add);
        add(id << 1 | 1, seg[id].add);
        seg[id].add = 0;
    }
    if (seg[id].tag) {
        tag(id << 1, seg[id].tag);
        tag(id << 1 | 1, seg[id].tag);
        seg[id].tag = 0;
    }
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].tag = seg[id].add = 0;
    seg[id].mul = 1;
    if (l == r) {
        seg[id].sum1 = seg[id].mn = a[l];
        seg[id].sum2 = 0;
        seg[id].cnt1 = 1;
        seg[id].cnt2 = 0;
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void modify2(int id, int ql, int qr, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (l >= ql && r <= qr) {
        mul(id, -1);
        add(id, val);
        return;
    }
    int mid = l + r >> 1;
    down(id);
    if (ql <= mid) modify2(id << 1, ql, qr, val);
    if (qr > mid) modify2(id << 1 | 1, ql, qr, val);
    up(id);
}
void modify1(int id, int ql, int qr, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (l >= ql && r <= qr) {
        if (seg[id].mn >= val) return tag(id, -val);
        if (l == r) {
            seg[id].cnt1 = seg[id].sum1 = 0;
            seg[id].cnt2 = 1;
            seg[id].sum2 = val - seg[id].mn;
            seg[id].mn = INF;
            return;
        }
    }
    int mid = l + r >> 1;
    down(id);
    if (ql <= mid) modify1(id << 1, ql, qr, val);
    if (qr > mid) modify1(id << 1 | 1, ql, qr, val);
    up(id);
}
int query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (l >= ql && r <= qr) return seg[id].sum1 + seg[id].sum2;
    int mid = l + r >> 1;
    down(id);
    if (qr <= mid) return query(id << 1, ql, qr);
    if (ql > mid) return query(id << 1 | 1, ql, qr);
    return query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        for (int i = 1; i <= m; i++) {
            int opt, l, r, x;
            cin >> opt >> l >> r;
            if (opt == 1) {
                cin >> x;
                modify2(1, l, r, x);
                modify1(1, l, r, x);
            } else
                cout << query(1, l, r) << endl;
        }
    }
}