// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int N = 1e5;
// int n, m, num[N];
// int dp[N];
// vector<int> vec[N];
// int main() {
//     while (cin >> num[n])
//         n++;
//     for (int i = 0; i < n; i++) {
//         dp[i] = 1;
//         int k = i;
//         for (int j = 0; j < i; j++)
//             if (num[i] < num[j] && dp[i] < dp[j] + 1) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 k = j;
//             }
//         if (k != i) vec[k].push_back(i);
//     }
//     int ans = 0, ans2 = 0;
//     for (int i = 0; i < n; i++) {
//         ans = max(ans, dp[i]);
//         ans2 += (vec[i].empty() ? 1 : 0);
//     }
//     cout << ans << endl;
//     cout << ans2 << endl;
// }

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5 + 10;
// const int INF = 1e9;
// int n, m, t, F[N], H[N];
// int main() {
//     t = 0, memset(F, 0, sizeof(F)), F[0] = INF;
//     for (int i = 1; i <= n; i++) {
//         int l = 0, r = t + 1;
//         while (r - l > 1) {
//             int m = l + (r - l) / 2;
//             if (F[m] >= H[i])
//                 l = m;
//             else
//                 r = m;
//         }
//         int x = l + 1;
//         if (x > t) t = x;
//         F[x] = H[i];
//     }
//     printf("%d\n", t);
// }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll a[maxn], n = 1, dp1[maxn], dp2[maxn], len1, len2;
inline void write(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    while (cin >> a[n]) {
        n++;
    }
    n--, len1 = 1, len2 = 1;
    dp1[1] = a[1], dp2[1] = a[1];
    for (ll i = 2; i <= n; i++) {
        if (a[i] <= dp1[len1]) {
            dp1[++len1] = a[i];
        } else {
            ll k1 = upper_bound(dp1 + 1, dp1 + len1 + 1, a[i], greater<ll>()) - dp1;
            dp1[k1] = a[i];
        }
        if (a[i] > dp2[len2]) {
            dp2[++len2] = a[i];
        } else {
            ll k2 = lower_bound(dp2 + 1, dp2 + len2 + 1, a[i]) - dp2;
            dp2[k2] = a[i];
        }
    }
    write(len1);
    puts("");
    write(len2);
    return 0;
}