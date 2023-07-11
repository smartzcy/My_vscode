#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int tot, ls[N], rs[N], sum[N], rt[N];
void up(int id) {
    sum[id] = sum[ls[id]] + sum[rs[id]];
}
void change(int &id, int l, int r, int pos, int val) {
    if (!id) id = ++tot;
    if (l == r) {
        sum[id] += val;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        change(ls[id], l, mid, pos, val);
    else
        change(rs[id], mid + 1, r, pos, val);
    up(id);
}
int query(int id, int l, int r, int ql, int qr) {
    if (!id) return 0;
    if (ql <= l && r <= qr) return sum[id];
    int mid = l + r >> 1, ans = 0;
    if (ql <= mid) ans += query(ls[id], l, mid, ql, qr);
    if (qr > mid) ans += query(rs[id], mid + 1, r, ql, qr);
    return ans;
}
int main() {
}