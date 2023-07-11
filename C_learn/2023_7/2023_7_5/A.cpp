#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
long long n, m, B;
long long a[N], id[N], l[N], r[N], sum[N], tag[N];
void build() {
    for (int i = 1; i <= n; i++) id[i] = (i - 1) / B + 1;
    for (int i = 1; i <= id[n]; i++) l[i] = (i - 1) * B + 1, r[i] = min(i * B, n);
    for (int i = 1; i <= n; i++) sum[id[i]] += a[i];
}
void bf_modify(int ql, int qr, int x) {
    for (int i = ql; i <= qr; i++) a[i] += x;
    sum[id[ql]] += (qr - ql + 1) * x;
}
long long bf_query(int ql, int qr) {
    long long ans = 0;
    ans += (qr - ql + 1) * tag[id[ql]];
    for (int i = ql; i <= qr; i++) ans += a[i];
    return ans;
}
void modify(int ql, int qr, int x) {
    int lid = id[ql], rid = id[qr];
    if (lid == rid) {
        bf_modify(ql, qr, x);
        return;
    }
    bf_modify(ql, r[lid], x);
    for (int i = lid + 1; i <= rid - 1; i++) tag[i] += x;
    bf_modify(l[rid], qr, x);
}
long long query(int ql, int qr) {
    int lid = id[ql], rid = id[qr];
    if (lid == rid) {
        return bf_query(ql, qr);
    }
    long long ans = 0;
    ans += bf_query(ql, r[lid]);
    for (int i = lid + 1; i <= rid - 1; i++) ans += tag[i] * (r[i] - l[i] + 1) + sum[i];
    ans += bf_query(l[rid], qr);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    B = sqrt(n);
    build();
    while (m--) {
        int k, x, y, z;
        cin >> k >> x >> y;
        if (k == 1) {
            cin >> z;
            modify(x, y, z);
        } else {
            cout << query(x, y) << endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// long long n, m, ans, sq;
// long long a[N], id[N], an[N];
// struct query {
//     int ql, qr, Id;
//     bool operator<(const query &o) const {
//         if (id[ql] == id[o.ql]) {
//             if (id[ql] % 2)
//                 return qr < o.qr;
//             else
//                 return qr > o.qr;
//         }
//         return id[ql] < id[o.ql];
//     }
// } A[N];
// void add(int x) {
//     ans += a[x];
// }
// void del(int x) {
//     ans -= a[x];
// }
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     sq = sqrt(n) + 1;
//     for (int i = 1; i <= n; i++) id[i] = (i - 1) / sq + 1;
//     for (int i = 1; i <= m; i++) {
//         cin >> A[i].ql >> A[i].qr;
//         A[i].Id = i;
//     }
//     sort(A + 1, A + m + 1);
//     for (int i = 1, l = 0, r = 0; i <= m; i++) {
//         while (l > A[i].ql) add(--l);
//         while (r < A[i].qr) add(++r);
//         while (l < A[i].ql) del(l++);
//         while (r > A[i].qr) del(r--);
//         an[A[i].Id] = ans;
//     }
//     for (int i = 1; i <= m; i++) {
//         cout << an[i] << endl;
//     }
// }