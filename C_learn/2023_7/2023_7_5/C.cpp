// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m, B;
// long long a[N], id[N], tag[N], ql[N], qr[N];
// vector<long long> vec[N];
// void build() {
//     for (int i = 1; i <= n; i++) id[i] = (i - 1) / B + 1, vec[id[i]].push_back(a[i]);
//     for (int i = 1; i <= id[n]; i++) ql[i] = (i - 1) * B + 1, qr[i] = i * B, sort(vec[i].begin(), vec[i].end());
// }
// void bf_modify(int l, int r, int x) {
//     for (int i = l; i <= r; i++) a[i] += x;
//     int lid = id[l];
//     vec[lid].clear();
//     for (int i = ql[lid]; i <= qr[lid]; i++) {
//         vec[lid].push_back(a[i]);
//     }
//     sort(vec[lid].begin(), vec[lid].end());
// }
// void modify(int l, int r, int x) {
//     int lid = id[l], rid = id[r];
//     if (lid == rid) {
//         bf_modify(l, r, x);
//         return;
//     }
//     bf_modify(l, qr[lid], x);
//     for (int i = lid + 1; i <= rid - 1; i++) tag[i] += x;
//     bf_modify(ql[rid], r, x);
// }
// long long bf_query(int l, int r, int c) {
//     long long ans = -1;
//     for (int i = l; i <= r; i++) {
//         if (a[i] + tag[id[l]] < c) ans = max(ans, a[i] + tag[id[l]]);
//     }
//     return ans;
// }
// int query(int l, int r, int c) {
//     long long ans = -1;
//     int lid = id[l], rid = id[r];
//     if (lid == rid) {
//         return bf_query(l, r, c);
//     }
//     ans = max(ans, bf_query(l, qr[lid], c));
//     for (int i = lid + 1; i <= rid - 1; i++) {
//         int k = lower_bound(vec[i].begin(), vec[i].end(), c - tag[i]) - vec[i].begin();
//         if (k != 0 && vec[i][k - 1] + tag[i] < c) {
//             ans = max(ans, *lower_bound(vec[i].begin(), vec[i].end(), c - tag[i]));
//         }
//     }
//     ans = max(ans, bf_query(ql[lid], r, c));
//     return ans;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     B = sqrt(n);
//     // build(); // 没写
//     for (int i = 1; i <= n; i++) {
//         int opt, l, r, c;
//         cin >> opt >> l >> r >> c;
//         if (!opt)
//             modify(l, r, c);
//         else
//             cout << query(l, r, c) << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int a[N], tag[N], id[N], ans, flag, n, B, ql[N], qr[N];
int opt, l, r, c;
vector<int> v[N];
void build() {
    for (int i = 1; i <= n; i++) id[i] = (i - 1) / B + 1, v[id[i]].push_back(a[i]);
    for (int i = 1; i <= id[n]; i++) ql[i] = (i - 1) * B + 1, qr[i] = i * B, sort(v[i].begin(), v[i].end());
}
void bf_modify(int l, int r, int x) {
    for (int i = l; i <= r; i++) a[i] += x;
    int lid = id[l];
    v[lid].clear();
    for (int i = ql[lid]; i <= qr[lid]; i++) {
        v[lid].push_back(a[i]);
    }
    sort(v[lid].begin(), v[lid].end());
}
void modify(int l, int r, int x) {
    int lid = id[l], rid = id[r];
    if (lid == rid) {
        bf_modify(l, r, x);
        return;
    }
    bf_modify(l, qr[lid], x);
    for (int i = lid + 1; i <= rid - 1; i++) tag[i] += x;
    bf_modify(ql[rid], r, x);
}
void query(int l, int r, int x) {
    flag = 0;
    ans = -10001010;
    for (int i = l; i <= min(id[l] * B, r); i++)
        if (a[i] + tag[id[l]] < x) {
            ans = max(a[i] + tag[id[l]], ans);
            flag = 1;
        }
    if (id[l] != id[r])
        for (int i = (id[r] - 1) * B + 1; i <= r; i++)
            if (a[i] + tag[id[r]] < x) {
                ans = max(ans, a[i] + tag[id[r]]);
                flag = 1;
            }
    for (int i = id[l] + 1; i <= id[r] - 1; i++) {
        int c = x - tag[i];
        int k = lower_bound(v[i].begin(), v[i].end(), c) - v[i].begin();
        if (k != 0 && v[i][k - 1] + tag[i] < x) {
            flag = 1;
            ans = max(ans, v[i][k - 1] + tag[i]);
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << "-1" << endl;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    B = sqrt(n);
    build();
    for (int i = 0; i < n; i++) {
        cin >> opt >> l >> r >> c;
        if (opt == 0)
            modify(l, r, c);
        else
            query(l, r, c);
    }
    return 0;
}