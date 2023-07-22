#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
long long n, k, a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n >= k) {
            long long s = 0, ans = 0;
            for (int i = 1; i <= n; i++) {
                if (i <= k)
                    s += a[i], ans = s;
                else
                    ans = max(ans, s - a[i - k] + a[i]), s = s - a[i - k] + a[i];
            }
            cout << ans + k * (k - 1) / 2 << endl;
        } else {
            long long ans = 0;
            for (int i = 1; i <= n; i++) ans += a[i];
            ans += n * k;
            ans -= n * (n + 1) / 2;
            cout << ans << endl;
        }
    }
}