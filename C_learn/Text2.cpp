#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int N = 4e6 + 5;
const int mod = 998244353;
int a[N];
int lowbit(int x) {
    return x & -x;
}
struct node {
    int sum, lazy;
    bool flag = false;
} seg[N];
bool check(int x) {
    return x + lowbit(x) == (x + x);
}
void build(int id, int l, int r) {
    seg[id].sum = 0;
    seg[id].lazy = 1;
    seg[id].flag = false;
    if (l == r) {
        seg[id].sum = a[l];
        seg[id].flag = check(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id].sum = (seg[id << 1].sum + seg[id << 1 | 1].sum) % mod;
    seg[id].flag = seg[id << 1].flag & seg[id << 1 | 1].flag;
}
void down(int id, int l, int r) {
    if (seg[id].lazy != 1) {
        seg[id << 1].lazy = (seg[id << 1].lazy * seg[id].lazy) % mod;
        seg[id << 1 | 1].lazy = (seg[id << 1 | 1].lazy * seg[id].lazy) % mod;
        seg[id << 1].sum = (seg[id << 1].sum * seg[id].lazy) % mod;
        seg[id << 1 | 1].sum = (seg[id << 1 | 1].sum * seg[id].lazy) % mod;
        seg[id].lazy = 1;
    }
}
void modify(int id, int l, int r, int ql, int qr) {
    if (l == r) {
        if (seg[id].flag)
            seg[id].sum = (seg[id].sum * 2) % mod;
        else
            seg[id].sum = seg[id].sum + lowbit(seg[id].sum);

        if (check(seg[id].sum)) seg[id].flag = true;
        return;
    }
    if (l >= ql && r <= qr && seg[id].flag) {
        seg[id].sum = (seg[id].sum * 2) % mod;
        seg[id].lazy = (seg[id].lazy * 2) % mod;
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(id << 1, l, mid, ql, qr);
    if (qr > mid)
        modify(id << 1 | 1, mid + 1, r, ql, qr);
    seg[id].sum = (seg[id << 1].sum + seg[id << 1 | 1].sum) % mod;
    seg[id].flag = seg[id << 1].flag & seg[id << 1 | 1].flag;
}
int query(int id, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
        return seg[id].sum % mod;
    }
    down(id, l, r);
    int sum = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        sum = (sum + query(id << 1, l, mid, ql, qr)) % mod;
    if (qr > mid) {
        sum = (sum + query(id << 1 | 1, mid + 1, r, ql, qr)) % mod;
    }
    return sum % mod;
}
signed main() {
    int t;
    scanf("%lld", &t);
    int n, m;
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i <= n * 4; i++) {
            seg[i].sum = seg[i].flag = 0;
            seg[i].lazy = 1;
        }
        scanf("%lld", &m);
        build(1, 1, n);
        for (int i = 1; i <= m; i++) {
            int op, l, r;
            scanf("%lld%lld%lld", &op, &l, &r);
            if (op == 1) {
                modify(1, 1, n, l, r);
            } else
                printf("%lld\n", query(1, 1, n, l, r) % mod);
        }
    }
}
