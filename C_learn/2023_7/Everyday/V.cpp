#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 200010;
int t;
int a[maxn], b[maxn], n;
int dp[maxn];
void solve() {
    scanf("%d", &n);
    int sum = 0, res = 0;
    int all = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        all += a[i];
        ans += a[i] * a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        all += b[i];
        ans += b[i] * b[i];
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        res += a[i];
        b[i] -= a[i];
        sum += b[i];
    }
    memset(dp, 0, sizeof(dp));
    int m = sum / 2;
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= b[i]; --j)
            dp[j] = max(dp[j], dp[j - b[i]] + b[i]);
    int suma = res + dp[m];
    int sumb = all - suma;
    ans = ans * (n - 2) + suma * suma + sumb * sumb;
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}
