#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, B;
int a[N], id[N], tag[N], ql[N], qr[N];
vector<int> vec[N];
void build() {
    for (int i = 1; i <= n; i++) id[i] = (i - 1) / B + 1, vec[id[i]].push_back(a[i]);
    for (int i = 1; i <= id[n]; i++) ql[i] = (i - 1) * B + 1, qr[i] = i * B, sort(vec[i].begin(), vec[i].end());
}
void bf_modify(int l, int r, int x) {
    for (int i = l; i <= r; i++) a[i] += x;
    int lid = id[l];
    vec[lid].clear();
    for (int i = ql[lid]; i <= qr[lid]; i++) {
        vec[lid].push_back(a[i]);
    }
    sort(vec[lid].begin(), vec[lid].end());
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
int bf_query(int l, int r, int c) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] + tag[id[l]] < c) ans++;
    }
    return ans;
}
int query(int l, int r, int c) {
    int ans = 0;
    int lid = id[l], rid = id[r];
    if (lid == rid) {
        for (int i = l; i <= r; i++) {
            if (a[i] + tag[lid] < c) ans++;
        }
        return ans;
    }
    ans += bf_query(l, qr[lid], c);
    for (int i = lid + 1; i <= rid - 1; i++) {
        ans += (lower_bound(vec[i].begin(), vec[i].end(), c - tag[i]) - vec[i].begin());
    }
    ans += bf_query(ql[lid], r, c);
    return ans;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    B = sqrt(n);
    build(); // 没写
    for (int i = 1; i <= n; i++) {
        int opt, l, r, c;
        cin >> opt >> l >> r >> c;
        if (!opt)
            modify(l, r, c);
        else
            cout << query(l, r, c * c) << endl;
    }
}