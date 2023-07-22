// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 2e5 + 10;
// int n, q, a[N];
// struct node {
//     int l, r;
//     int len, ren;
//     long long sum;
// } seg[N << 2];
// void up(int id) {
//     seg[id].sum = seg[id << 1].sum + seg[id << 1 | 1].sum;
//     seg[id].len = seg[id << 1].len, seg[id].ren = seg[id << 1 | 1].ren;
//     if (a[seg[id << 1].r] <= a[seg[id << 1 | 1].l]) {
//         if (seg[id << 1].len == seg[id << 1].r - seg[id << 1].l + 1) seg[id].len = seg[id << 1].len + seg[id << 1 | 1].len;
//         if (seg[id << 1 | 1].len == seg[id << 1 | 1].r - seg[id << 1 | 1].l + 1) seg[id].len = seg[id << 1 | 1].ren + seg[id << 1].ren;
//         seg[id].sum += 1ll * seg[id << 1].ren * seg[id << 1 | 1].len;
//     }
// }
// void build(int id, int l, int r) {
//     seg[id].l = l;
//     seg[id].r = r;
//     if (l == r) {
//         seg[id].sum = seg[id].len = seg[id].ren = 1;
//         return;
//     }
//     int mid = l + r >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }
// void modify(int id, int pos, int val) {
//     if (seg[id].l == seg[id].r) {
//         a[pos] = val;
//         return;
//     }
//     int mid = seg[id].l + seg[id].r >> 1;
//     if (pos <= mid)
//         modify(id << 1, pos, val);
//     else
//         modify(id << 1 | 1, pos, val);
//     up(id);
// }
// long long query(int id, int l, int r) {
//     if (seg[id].l >= l && seg[id].r <= r) return seg[id].sum;
//     int mid = seg[id].l + seg[id].r >> 1;
//     long long ans = 0;
//     if (l <= mid) ans += query(id << 1, l, r);
//     if (r > mid) ans += query(id << 1 | 1, l, r);
//     if (a[seg[id << 1].r] <= a[seg[id << 1 | 1].l]) {
//         long long lsum = min(mid - l + 1, seg[id << 1].ren), rsum = min(r - mid, seg[id << 1 | 1].len);
//         if (lsum > 0 && rsum > 0) ans += lsum * rsum;
//     }
//     return ans;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     build(1, 1, n);
//     while (q--) {
//         int op, x, y;
//         cin >> op >> x >> y;
//         if (op == 1)
//             modify(1, x, y);
//         else
//             cout << query(1, x, y) << '\n';
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
template <typename T>
inline void read(T &a) {
    char c = getchar();
    T x = 0, f = 1;
    while (!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    a = f * x;
}
int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}
struct Node {
    int l, r;
    int len, ren;
    ll sum;

} tr[N * 4];
int a[N];
int n, m;

void push(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].len = tr[u << 1].len, tr[u].ren = tr[u << 1 | 1].ren;
    if (a[tr[u << 1].r] <= a[tr[u << 1 | 1].l]) {
        if (tr[u << 1].len == tr[u << 1].r - tr[u << 1].l + 1) tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
        if (tr[u << 1 | 1].ren == tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) tr[u].ren = tr[u << 1 | 1].ren + tr[u << 1].ren;
        tr[u].sum += 1ll * tr[u << 1].ren * tr[u << 1 | 1].len;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = tr[u].len = tr[u].ren = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    push(u);
}

void modify(int u, int x, int val) {
    if (tr[u].l == tr[u].r) {
        a[x] = val;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (x <= mid)
        modify(u << 1, x, val);
    else
        modify(u << 1 | 1, x, val);
    push(u);
}

ll query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll ans = 0;
    if (l <= mid) ans = query(u << 1, l, r);
    if (r > mid) ans += query(u << 1 | 1, l, r);
    if (a[tr[u << 1].r] <= a[tr[u << 1 | 1].l]) {
        ll lsum = min(mid - l + 1, tr[u << 1].ren), rsum = min(r - mid, tr[u << 1 | 1].len);
        if (lsum > 0 && rsum > 0) ans += lsum * rsum;
    }
    return ans;
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        read(op), read(x), read(y);
        if (op == 1)
            modify(1, x, y);
        else { cout << (query(1, x, y)) << endl; }
    }
    return 0;
}
