#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, q, l[N], r[N];
int tot, ls[N], rs[N], sum[N], a[N], rt[N];
void change(int &rt, int pre, int l, int r, int pos) {
    rt = ++tot;
    ls[rt] = ls[pre], rs[rt] = rs[pre], sum[rt] = sum[pre] + 1;
    if (l == r) return;
    int mid = l + r >> 1;
    if (pos <= mid)
        change(ls[rt], ls[pre], l, mid, pos);
    else
        change(rs[rt], rs[pre], mid + 1, r, pos);
}
int query(int rt, int pre, int l, int r, int k) {
    if (l == r) return l;
    int cnt = sum[ls[rt]] - sum[ls[pre - 1]];
    int mid = l + r >> 1;
    if (cnt >= k)
        return query(ls[rt], ls[pre], l, mid, k);
    else
        return query(rs[rt], rs[pre], mid + 1, r, k - cnt);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            change(rt[i], rt[i - 1], 1, n, a[i]);
        }
        cin >> q;
        for (int i = 1, k; i <= q; i++) {
            cin >> l[i] >> r[i] >> k;
            int m = r[i] - l[i] + 1;
        }
    }
}