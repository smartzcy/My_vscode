#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, B;
int id[N], l[N], r[N];
pair<int, int> p[N];
int a[N];
void build() {
    for (int i = 1; i <= n; i++) id[i] = (i - 1) / B + 1;
    for (int i = 1; i <= id[n]; i++) l[i] = (i - 1) * B + 1, r[i] = i * B;
    for (int i = 1; i <= id[n]; i++) {
        int maxx = 0, max_num = 0;
        map<int, int> map1;
        for (int j = l[i]; j <= r[i]; j++) {
            map1[a[j]]++;
            if (map1[a[j]] > max_num)
                max_num = map1[a[j]], maxx = a[j];
            else if (map1[a[j]] == max_num && a[j] < maxx)
                maxx = a[j];
        }
        p[i] = {maxx, max_num};
        map1.clear();
    }
}
int query(int l, int r) {
    int lid = id[l], rid = id[r];
    if (lid == rid) {
        }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    B = sqrt(n);
    build();
    int ans = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l = (l + ans - 1) % n + 1;
        r = (r + ans - 1) % n + 1;
        if (l > r) swap(l, r);
        ans = query(l, r);
        cout << ans << endl;
    }
}