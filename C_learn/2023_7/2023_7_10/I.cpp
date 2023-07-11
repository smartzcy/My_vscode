// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e2 + 10;
// int n, m;
// int dp[210][210], f[210][210];
// int a[210], pre[210];
// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i], a[n + i] = a[i];
//     }
//     for (int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
//     for (int i = 0; i <= 2 * N; i++)
//         for (int j = 0; j <= 2 * N; j++) {
//             f[i][j] = INF;
//             if (i == j) f[i][j] = 0;
//         }
//     for (int i = 2; i <= n; i++) {
//         for (int l = 1; l <= 2 * n - i; l++) {
//             int r = l + i - 1;
//             for (int k = l; k < r; k++) {
//                 dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
//                 f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
//                 dp[l][r] += pre[r] - pre[l - 1];
//                 f[l][r] += pre[r] - pre[l - 1];
//             }
//         }
//     }
//     int maxx = 0, minn = INF;
//     for (int i = 1; i <= n; i++) {
//         maxx = max(maxx, dp[i][i + n - 1]);
//         minn = min(minn, f[i][i + n - 1]);
//     }
//     cout << maxx << endl;
//     cout << minn << endl;
// }

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int a[200], n;
int f[200][200] = {0};
int fx[200][200] = {0};
int pre[200] = {0};
int ans_max = -1;
int ans_min = 0x7f7f7f7f;
int main() {
    int i, l, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }
    int len = (n << 1) - 1;
    for (i = 1; i <= len; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    memset(fx, 0x7f7f, sizeof(fx));
    for (i = 0; i <= 200; i++) fx[i][i] = 0;
    for (i = 2; i <= n; i++) {
        for (l = 1; l <= len - i + 1; l++) {
            int r = l + i - 1;
            for (k = l; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                fx[l][r] = min(fx[l][r], fx[l][k] + fx[k + 1][r]);
            }
            f[l][r] += pre[r] - pre[l - 1];
            fx[l][r] += pre[r] - pre[l - 1];
        }
    }
    for (i = 1; i <= n; i++) {
        ans_max = max(ans_max, f[i][i + n - 1]);
        ans_min = min(ans_min, fx[i][i + n - 1]);
    }
    printf("%d\n", ans_min);
    printf("%d", ans_max);
    return 0;
}