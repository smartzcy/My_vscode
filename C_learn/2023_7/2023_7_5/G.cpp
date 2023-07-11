// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// long long n, m, k, ans = 0, sq;
// long long a[N], id[N], an[N], b[N];
// struct query {
//     int ql, qr, Id;
//     bool operator<(const query &o) const {
//         if (id[ql] == id[o.ql]) {
//             return qr < o.qr;
//         }
//         return id[ql] < id[o.ql];
//     }
// } A[N];
// void add(int x) {
//     ans += (b[x] << 1 | 1);
//     b[x]++;
// }
// void del(int x) {
//     ans += 1 - (b[x] << 1);
//     b[x]--;
// }
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     sq = sqrt(n);
//     for (int i = 1; i <= n; i++) id[i] = (i - 1) / sq + 1;
//     for (int i = 1; i <= m; i++) {
//         cin >> A[i].ql >> A[i].qr;
//         A[i].Id = i;
//     }
//     sort(A + 1, A + m + 1);
//     for (int i = 1, l = 1, r = 0; i <= m; i++) {
//         while (l > A[i].ql) add(a[--l]);
//         while (r < A[i].qr) add(a[++r]);
//         while (l < A[i].ql) del(a[l++]);
//         while (r > A[i].qr) del(a[r--]);
//         an[A[i].Id] = ans;
//     }
//     for (int i = 1; i <= m; i++) {
//         cout << an[i] << endl;
//     }
// }

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 50005;
int n, m, pos[maxn], c[maxn];
LL s[maxn], ans;
struct Data {
    int l, r, id;
    LL a, b;
} a[maxn];
bool cmp(const Data &a, const Data &b) {
    if (pos[a.l] == pos[b.l])
        return a.r < b.r;
    return a.l < b.l;
}
bool cmp_id(const Data &a, const Data &b) {
    return a.id < b.id;
}
void update(int p, int add) {
    ans -= s[c[p]] * s[c[p]];
    s[c[p]] += add;
    ans += s[c[p]] * s[c[p]];
}
void solve() {
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        for (; r < a[i].r; r++)
            update(r + 1, 1);
        for (; r > a[i].r; r--)
            update(r, -1);
        for (; l < a[i].l; l++)
            update(l, -1);
        for (; l > a[i].l; l--)
            update(l - 1, 1);
        if (a[i].l == a[i].r) {
            a[i].a = 0;
            a[i].b = 1;
            continue;
        }
        a[i].a = ans - (a[i].r - a[i].l + 1);
        a[i].b = (a[i].r - a[i].l + 1) * 1LL * (a[i].r - a[i].l);
        LL g = __gcd(a[i].a, a[i].b);
        a[i].a /= g;
        a[i].b /= g;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    int block = sqrt(n);
    for (int i = 1; i <= n; i++)
        pos[i] = (i - 1) / block + 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i].l, &a[i].r);
        a[i].id = i;
    }
    sort(a + 1, a + m + 1, cmp);
    solve();
    sort(a + 1, a + m + 1, cmp_id);
    for (int i = 1; i <= m; i++)
        printf("%lld/%lld\n", a[i].a, a[i].b);
    return 0;
}