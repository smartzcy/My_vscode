#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, p;
int a[N];
struct node {
    int l, r;
    int sum;
    int lazy, lazy2 = 1;
} seg[N << 2];
void up(int id) {
    seg[id].sum = (seg[id << 1].sum + seg[id << 1 | 1].sum) % p;
}
void settag(int id, int tag) {
    seg[id].lazy = (seg[id].lazy + tag) % p;
    seg[id].sum = (seg[id].sum + tag * (seg[id].r - seg[id].l + 1)) % p;
}
void down(int id) {
    seg[id << 1].sum = (seg[id << 1].sum * seg[id].lazy2 + seg[id].lazy2 * (seg[id << 1].r - seg[id << 1].l + 1)) % p;
    seg[id << 1 | 1].sum = (seg[id << 1 | 1].sum * seg[id].lazy2 + seg[id].lazy2 * (seg[id << 1 | 1].r - seg[id << 1 | 1].l + 1)) % p;
    seg[id << 1].lazy2 = (seg[id].lazy2 * seg[id].lazy2) % p;
    seg[id << 1 | 1].lazy2 = (seg[id].lazy2 * seg[id].lazy2) % p;
    seg[id << 1].lazy = (seg[id << 1].lazy * seg[id].lazy2 + seg[id].lazy) % p;
    seg[id << 1 | 1].lazy = (seg[id << 1 | 1].lazy * seg[id].lazy2 + seg[id].lazy) % p;
    seg[id].lazy2 = 1;
    seg[id].lazy = 0;
}
void modify(int id, int ql, int qr, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        settag(id, val * seg[id].lazy2);
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    modify(id << 1, ql, qr, val);
    modify(id << 1 | 1, ql, qr, val);
    up(id);
}
void modify2(int id, int ql, int qr, int val) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        seg[id].lazy = (seg[id].lazy * val) % p;
        seg[id].lazy2 = (seg[id].lazy2 * val) % p;
        seg[id].sum = (seg[id].sum * val) % p;
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    modify(id << 1, ql, qr, val);
    modify(id << 1 | 1, ql, qr, val);
    up(id);
}
void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    up(id);
}
int query(int id, int ql, int qr) {
    int l = seg[id].l;
    int r = seg[id].r;
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return seg[id].sum % p;
    down(id);
    return (query(id << 1, ql, qr) % p + query(id << 1 | 1, ql, qr) % p) % p;
}
int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            int num;
            cin >> num;
            modify2(1, x, y, num);
        } else if (k == 2) {
            int num;
            cin >> num;
            modify(1, x, y, num);
        } else {
            cout << query(1, x, y) << endl;
        }
    }
}