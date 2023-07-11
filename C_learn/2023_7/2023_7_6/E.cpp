#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
int a[N], c[N], ans[N], flag[N];
void read(int &x) {
    char ch = getchar();
    int f = 1;
    x = 0;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
struct node {
    int l, r;
    int id;
} seg[N];
bool cmp(const node &a, const node &b) {
    return a.r < b.r;
}
int lowbit(int x) {
    return x & -x;
}
void add(int x, int now) {
    for (int i = x; i <= N; i += lowbit(i)) c[i] += now;
}
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    read(m);
    for (int i = 1; i <= m; i++) {
        read(seg[i].l);
        read(seg[i].r);
        seg[i].id = i;
    }
    sort(seg + 1, seg + 1 + m, cmp);
    int next = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = next; j <= seg[i].r; j++) {
            if (flag[a[j]]) add(flag[a[j]], -1); // 检查之前是否出现过
            add(j, 1);
            flag[a[j]] = j;
        }
        next = seg[i].r + 1;
        ans[seg[i].id] = sum(seg[i].r) - sum(seg[i].l - 1);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #define maxn 1000010
// using namespace std;
// int n, m;
// int a[maxn], ans[maxn];
// int vis[maxn], tree[maxn];
// struct QUE {
//     int l;
//     int r;
//     int id;
// } q[maxn];
// void read(int &x) {
//     char ch = getchar();
//     int f = 1;
//     x = 0;
//     while (!isdigit(ch) && ch ^ '-') ch = getchar();
//     if (ch == '-') f = -1, ch = getchar();
//     while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
//     x *= f;
// }
// bool cmp(const QUE &a, const QUE &b) {
//     return a.r < b.r;
// }
// int lowbit(int x) {
//     return x & (-x);
// }
// void modify(int p, int v) {
//     for (; p <= n; p += lowbit(p))
//         tree[p] += v;
// }
// int query(int p) {
//     int res = 0;
//     for (; p; p -= lowbit(p))
//         res += tree[p];
//     return res;
// }
// int main() {
//     read(n);
//     for (int i = 1; i <= n; ++i) read(a[i]);
//     read(m);
//     for (int i = 1; i <= m; ++i) {
//         read(q[i].l);
//         read(q[i].r);
//         q[i].id = i;
//     }
//     sort(q + 1, q + m + 1, cmp);
//     int pow = 1;
//     for (int i = 1; i <= m; ++i) {
//         for (int j = pow; j <= q[i].r; ++j) {
//             if (vis[a[j]]) modify(vis[a[j]], -1);
//             modify(j, 1);
//             vis[a[j]] = j;
//         }
//         pow = q[i].r + 1;
//         ans[q[i].id] = query(q[i].r) - query(q[i].l - 1);
//     }
//     for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
//     return 0;
// }