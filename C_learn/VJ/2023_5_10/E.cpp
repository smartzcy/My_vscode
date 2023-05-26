#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, k, a[N], b[N], na[N], nb[N], cnt;
map<long long, long long> map1;
long long calc(long long t) {
    if (t <= k) return t;
    if (t % k == 0) return (t / k - 1) * k * 2 + k;
    return t / k * k * 2 + t % k;
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 1; i <= n;) {
        int j;
        for (j = i; j <= n && a[j] == a[i]; ++j)
            ;
        na[++cnt] = a[i];
        while (i < j) nb[cnt] += b[i++];
    }
    for (int i = 1; i <= cnt; ++i) map1[na[i]] += calc(nb[i]);
    cout << map1.size() << endl;
    for (auto [u, v] : map1) cout << u << " " << v << endl;
}