#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, x;
int a[N], l[N], r[N], ll[N], rr[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    memset(l, N, sizeof(l));
    memset(ll, N, sizeof(ll));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
    }
    for (int i = 1; i <= x; i++) rr[i] = max(rr[i - 1], r[i]);
    for (int i = x; i >= 1; i--) ll[i] = min(ll[i + 1], l[i]);
    long long ans = 0;
    int pl = 1, pr = x;
    while (pl <= x && rr[pl - 1] <= l[pl]) pl++;
    while (pr >= 1 && ll[pr + 1] >= r[pr]) pr--;
    for (int i = 1, j = pr; i <= pl; i++) {
        while (j <= x && (j < i || rr[i - 1] >= ll[j + 1])) j++;
        ans += x - j + 1;
    }
    cout << ans;
}