#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, k, a[N], ans;
long long lcm(long long n, long long m) {
    return n * m / __gcd(n, m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (long long i = 1; i < (1 << k); i++) {
        long long res = 1, tot = 0;
        for (long long j = 1; j <= k; j++) {
            if (i & (1 << (j - 1))) {
                res = lcm(res, a[j]);
                tot++;
            }
        }
        if (tot & 1)
            ans += n / res;
        else
            ans -= n / res;
    }
    cout << n - ans << endl;
}