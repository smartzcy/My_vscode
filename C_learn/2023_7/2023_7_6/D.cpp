// // #include <iostream>
// // #include <algorithm>
// // #include <vector>
// // using namespace std;
// // const int N = 1e6 + 5;
// // long long n, k, a[N];
// // vector<int> ans;
// // struct node {
// //     int l, r;
// //     long long sum, lazy;
// // } seg[N << 2];
// // void settag(int id, long long tag) {
// //     seg[id].sum += tag;
// //     seg[id].lazy += tag;
// // }
// // void up(int id) {
// //     seg[id].sum = max(seg[id << 1].sum, seg[id << 1 | 1].sum);
// // }
// // void down(int id) {
// //     if (seg[id].lazy == 0) return;
// //     settag(id << 1, seg[id].lazy);
// //     settag(id << 1 | 1, seg[id].lazy);
// //     seg[id].lazy = 0;
// // }
// // void build(int id, int l, int r) {
// //     seg[id].l = l;
// //     seg[id].r = r;
// //     if (l == r) {
// //         seg[id].sum = 0;
// //         return;
// //     }
// //     int mid = (l + r) >> 1;
// //     build(id << 1, l, mid);
// //     build(id << 1 | 1, mid + 1, r);
// //     up(id);
// // }
// // void modify(int id, int ql, int qr, int val) {
// //     int l = seg[id].l;
// //     int r = seg[id].r;
// //     if (ql > r || qr < l) return;
// //     if (ql <= l && r <= qr) {
// //         settag(id, val);
// //         return;
// //     }
// //     down(id);
// //     int mid = (l + r) >> 1;
// //     modify(id << 1, ql, qr, val);
// //     modify(id << 1 | 1, ql, qr, val);
// //     up(id);
// // }
// // void query(int id, int l, int r) {
// //     if (seg[id].sum < k) return;
// //     if (l == r && seg[id].sum >= k) {
// //         ans.push_back(l);
// //         return;
// //     }
// //     down(id);
// //     int mid = l + r >> 1;
// //     query(id << 1, l, mid);
// //     query(id << 1 | 1, mid + 1, r);
// // }
// // int main() {
// //     cin >> n >> k;
// //     build(1, 1, N);
// //     for (int i = 1; i <= n; i++) {
// //         int l, r;
// //         cin >> l >> r;
// //         modify(1, l, r, 1);
// //     }
// //     query(1, 1, N);
// //     cout << (ans.size() + 1) / 2 << endl;
// //     for (int i = 0; i < ans.size(); i += 2) {
// //         cout << ans[i] << " " << ans[i + 1] << endl;
// //     }
// // }

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e6 + 10;
// int n, m;
// int a[N], c[N], ans[N], flag[N];
// void read(int &x) {
//     char ch = getchar();
//     int f = 1;
//     x = 0;
//     while (!isdigit(ch) && ch ^ '-') ch = getchar();
//     if (ch == '-') f = -1, ch = getchar();
//     while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
//     x *= f;
// }
// struct node {
//     int l, r;
//     int id;
// } seg[N];
// bool cmp(const node &a, const node &b) {
//     return a.r < b.r;
// }
// int lowbit(int x) {
//     return x & -x;
// }
// void add(int x, int now) {
//     for (int i = x; i <= N; i += lowbit(i)) c[i] += now;
// }
// int sum(int x) {
//     int res = 0;
//     for (int i = x; i; i -= lowbit(i)) res += c[i];
//     return res;
// }
// int main() {
//     read(n);
//     read(m);
//     for (int i = 1; i <= n; i++) {
//         read(seg[i].l);
//         read(seg[i].r);
//         seg[i].id = i;
//     }
//     sort(seg + 1, seg + 1 + n, cmp);
//     int next = 1;
//     for (int i = 1; i <= n; i++) {
//         add(seg[i].l - 1, -1);
//         add(seg[i].r, 1);
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, k, now = 0, lid = 0, flag = 0;
vector<pair<int, int>> vec, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        vec.push_back({l, 1});
        vec.push_back({r + 1, -1});
    }
    sort(vec.begin(), vec.end());
    for (auto &[v, typ] : vec) {
        now += typ;
        if (now >= k) {
            if (!flag) lid = v;
            flag = 1;
        } else if (flag) {
            ans.push_back({lid, v - 1});
            flag = 0;
        }
    }
    cout << ans.size() << endl;
    for (auto &[x, y] : ans) cout << x << " " << y << endl;
}