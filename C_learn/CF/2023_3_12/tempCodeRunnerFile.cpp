#include <iostream>
using namespace std;
const int N = 3e5 + 5;
const int mod = 998244353;
long long n, q, a[N];
struct node {
    int l, r;
    long long sum;
    int x[25];
} seg[N << 2];
void up(int id) {
    seg[id].sum = (seg[id << 1].sum + seg[id << 1 | 1].sum) % mod;
    for (int i = 0; i < 25; i++) seg[id].x[i] = seg[id << 1].x[i] + seg[id << 1 | 1].x[i];
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].sum = (a[l] * a[l]) % mod;
        for (int i = 0; i < 25; i++) seg[id].x[i] = a[l] >> i & 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
void modify(int id, int ql, int qr, int val) {
    if (seg[id].l == seg[id].r) {
        long long sum = 0;
        for (int i = 0; i < 25; i++) {
            if (seg[id].x[i] && (val >> i & 1))
                sum |= 1 << i;
            else
                seg[id].x[i] = 0;
        }
        seg[id].sum = (sum * sum) % mod;
    }
    if (ql <= seg[id].l && qr >= seg[id].r) {
        bool f = true;
        for (int i = 0; i < 25; i++) {
            if (seg[id].x[i] && (val >> i & 1) == 0) {
                f = false;
                break;
            }
        }
        if (f) return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (ql <= mid) modify(id << 1, ql, qr, val);
    if (qr > mid) modify(id << 1 | 1, ql, qr, val);
    up(id);
}
long long query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[id].sum;
    return (query(id << 1, ql, qr) + query(id << 1 | 1, ql, qr)) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int k, l, r, x;
        cin >> k >> l >> r;
        if (k == 1) {
            cin >> x;
            modify(1, l, r, x);
        } else {
            cout << query(1, l, r) << endl;
        }
    }
}
