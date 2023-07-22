// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 2e5 + 10;
// int n, m, a[N], dp[N], mp[N];
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n;
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//             a[i]--;
//             dp[i] = 0;
//             mp[i] = n;
//         }
//         dp[0] = 1;
//         mp[a[0]] = 0;
//         for (int i = 1; i < n; i++) {
//             dp[i] = min(dp[i - 1] + 1, dp[mp[a[i]]]);
//             mp[a[i]] = min(dp[i - 1], mp[a[i]]);
//         }
//         cout << n - dp[n - 1] << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, T;
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        vector<long long> a(n + 1), dp(n + 1), mx(n + 1, -INF);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1], i + mx[a[i]]);
            mx[a[i]] = max(mx[a[i]], dp[i - 1] - i + 1);
        }
        cout << dp[n] << endl;
    }
}