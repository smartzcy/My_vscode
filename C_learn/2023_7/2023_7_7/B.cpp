// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// using namespace std;
// const int N = 3e5 + 10;
// int n, q, a[N], id[N], sq, an[N];
// struct query {
//     int ql, qr, Id, k;
//     bool operator<(const query &o) const {
//         if (id[ql] == id[o.ql]) {
//             return qr < o.qr;
//         }
//         return id[ql] < id[o.ql];
//     }
// } A[N];
// struct node {
//     int l, r;
//     int sum;
// } seg[N << 2];
// void up(int id) {
//     seg[id].sum = max(seg[id << 1].sum, seg[id << 1 | 1].sum);
// }
// void build(int id, int l, int r) {
//     seg[id].l = l;
//     seg[id].r = r;
//     if (l == r) {
//         seg[id].sum = 0;
//         return;
//     }
//     int mid = (l + r) >> 1;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     up(id);
// }
// int query(int id, int k) {
//     int l = seg[id].l;
//     int r = seg[id].r;
//     if (l == r) {
//         if (seg[id].sum >= k) return l;
//         return -1;
//     }
//     if (seg[id << 1].sum >= k)
//         return query(id << 1, k);
//     else if (seg[id << 1 | 1].sum >= k)
//         return query(id << 1 | 1, k);
//     else
//         return -1;
// }
// void change(int id, int pos, int val) {
//     if (seg[id].l == seg[id].r) {
//         seg[id].sum += val;
//         return;
//     }
//     int mid = (seg[id].l + seg[id].r) >> 1;
//     if (pos <= mid)
//         change(id << 1, pos, val);
//     else
//         change(id << 1 | 1, pos, val);
//     up(id);
// }
// int main() {
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     sq = sqrt(n);
//     for (int i = 1; i <= n; i++) id[i] = (i - 1) / sq + 1;
//     for (int i = 1; i <= q; i++) {
//         cin >> A[i].ql >> A[i].qr >> A[i].k;
//         A[i].Id = i;
//     }
//     sort(A + 1, A + q + 1);
//     for (int i = 1, l = 1, r = 0; i <= q; i++) {
//         while (l > A[i].ql) change(1, a[--l], 1);
//         while (r < A[i].qr) change(1, a[r++], 1);
//         while (l < A[i].ql) change(1, a[l++], -1);
//         while (r > A[i].qr) change(1, a[++r], -1);
//         an[A[i].Id] = query(1, ceil((A[i].ql - A[i].ql + 1) / A[i].k));
//     }
//     for (int i = 1; i <= q; i++) {
//         cout << an[i] << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 3e5 + 100;
int n, q, tot, ans;
vector<int> vec;
int a[N], rt[N];
int ls[N * 100], rs[N * 100], sum[N * 100];
void change(int &rt, int pre, int l, int r, int pos) {
    rt = ++tot;
    ls[rt] = ls[pre], rs[rt] = rs[pre], sum[rt] = sum[pre] + 1;
    if (l == r)
        return;
    int mid = l + r >> 1;
    if (pos <= mid)
        change(ls[rt], ls[pre], l, mid, pos);
    else
        change(rs[rt], rs[pre], mid + 1, r, pos);
}
void query(int rt, int pre, int l, int r, int k) {
    if (l == r) {
        if (sum[rt] - sum[pre] > k && (ans == -1 || ans > l)) {
            ans = l;
        }
        return;
    }
    int cnt = sum[rt] - sum[pre];
    int mid = l + r >> 1;
    if (cnt > k) {
        query(ls[rt], ls[pre], l, mid, k);
        query(rs[rt], rs[pre], mid + 1, r, k);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        change(rt[i], rt[i - 1], 1, n, a[i]);
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        ans = -1;
        query(rt[r], rt[l - 1], 1, n, (r - l + 1) / k);
        cout << ans << endl;
    }
}
