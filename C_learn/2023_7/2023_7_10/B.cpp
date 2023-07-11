#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e6 + 10;
long long n, m, k, ans = 0;
long long a[31], b[31], c[31], dp[N];
long long check(long long x) {
    long long an = 0;
    while (x) {
        an++;
        x &= (x - 1);
    }
    return an;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> k;
        c[i] = 0;
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            x--;
            c[i] |= (1 << x);
        }
    }
    m = 1 << n;
    for (int i = 0; i <= m; i++) dp[i] = -INF;
    dp[0] = 0;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                long long tmp = i ^ (1 << j);
                if (dp[tmp] == -INF) continue;
                if ((tmp | c[j]) == tmp) {
                    int time = check(i);
                    dp[i] = max(dp[i], dp[tmp] + a[j] * time + b[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
    }
    cout << ans << endl;
}