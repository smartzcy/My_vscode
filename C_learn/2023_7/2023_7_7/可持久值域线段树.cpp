#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 100;
int n, q, tot;
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
int query(int rt, int pre, int l, int r, int k) {
    if (l == r) return l;
    int cnt = sum[ls[rt]] - sum[ls[pre]];
    int mid = l + r >> 1;
    if (cnt >= k) return query(ls[rt], ls[pre], l, mid, k);
    return query(rs[rt], rs[pre], mid + 1, r, k - cnt);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++) {
        int k = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        change(rt[i], rt[i - 1], 1, n, k);
    }
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << vec[query(rt[r], rt[l - 1], 1, n, k) - 1] << endl;
    }
}
