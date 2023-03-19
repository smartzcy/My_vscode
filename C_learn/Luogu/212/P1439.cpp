// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m;
// int a[N], b[N];
// long long dp[N];
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= n; i++) cin >> b[i];
//     for (int i = 1; i <= n; i++) {
//         dp[i] = 1;
//         for (int j = 1; j < i; j++)
//             if (a[j] == b[i - 1]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 break;
//             }
//     }
//     long long ans = 0;
//     for (int i = 1; i <= n; i++)
//         ans = max(ans, dp[i]);
//     cout << ans << endl;
// }

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 101000;
int b[N], idx[N], n;
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int main() {
    n = read();
    memset(b, 0x3f, sizeof(b));
    for (int i = 1; i <= n; i++)
        idx[read()] = i;
    for (int i = 1; i <= n; i++) {
        int x = idx[read()];
        *lower_bound(b + 1, b + n + 1, x) = x;
    }
    printf("%d", lower_bound(b + 1, b + n + 1, b[0]) - b - 1);
    return 0;
}