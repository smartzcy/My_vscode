// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5;
// int n, m;
// long long p[N], d[N];
// pair<long long, long long> dp[N][2];
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> p[i];
//     for (int i = 1; i <= n; i++) cin >> d[i];
//     dp[0][0] = {m, 0};
//     dp[0][1] = {m, 0};
//     for (int i = 1; i <= n; i++) {
//         long long x = dp[i - 1][0].first * p[i] + dp[i - 1][0].second;
//         long long y = dp[i - 1][1].first * p[i] + dp[i - 1][1].second;
//         long long z = m * p[i];
//         if (x > y && x > z)
//             dp[i][1] = {dp[i - 1][0].first / d[i], x};
//         else if (y > x && y > z)
//             dp[i][1] = {dp[i - 1][1].first / d[i], y};
//         else
//             dp[i][1] = {m / d[i], z};
//         if (dp[i - 1][0].second > dp[i - 1][1].second)
//             dp[i][0] = {dp[i - 1][0].first, dp[i - 1][0].second};
//         else
//             dp[i][0] = {dp[i - 1][1].first, dp[i - 1][1].second};
//     }
//     cout << max(dp[n][0].second, dp[n][1].second) << endl;
// }

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long p[N], d[N];
long long vis[N], f[N], g[N], val[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    vis[m] = 1;
    int cnt = 0;
    val[++cnt] = m;
    for (int i = m; i >= 1; i--) {
        if (vis[i]) {
            for (int j = 1; j <= i; j++)
                vis[i / j] = 1;
            val[++cnt] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cnt; j++)
            f[val[j] / d[i]] = max(f[val[j] / d[i]], g[val[j]] + val[j] * p[i]);
        for (int j = 1; j <= cnt; j++)
            g[val[j]] = f[val[j]];
    }
    long long ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}