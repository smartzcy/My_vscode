// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include <cmath>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m;
// long long c[37], w[37];
// long long vis[37][37], flag[37];
// long long dp[37], ans[37];
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) cin >> c[i];
//     for (int i = 0; i < n; i++) cin >> w[i];
//     for (int i = 1, u, v; i <= m; i++) {
//         cin >> u >> v;
//         u--, v--;
//         vis[u][v] = 1;
//     }
//     vis[0][0] = 1;
//     int m = 1 << n;
//     for (int i = 1; i < m; i++) {
//         for (int j = 0; j < n; j++) flag[j] = 0, dp[j] = 0;
//         int last = 0;
//         for (int j = 0; j < n; j++) {
//             if (i & (1 << j)) {
//                 if (!vis[last][j]) break;
//                 if (flag[c[j]])
//                     dp[j] = max(dp[j], dp[last]);
//                 else {
//                     dp[j] = max(dp[j], dp[last] + w[c[j] - 1]);
//                     flag[c[j]] = 1;
//                 }
//                 ans[j] = max(ans[j], dp[j]);
//                 last = j;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) cout << ans[i] << endl;
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, c[N], w[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        }
}