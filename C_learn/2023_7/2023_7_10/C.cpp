#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e3 + 10;
long long n, k, cnt[N], tot, st[N];
long long dp[11][100][N];
int main() {
    cin >> n >> k;
    for (int i = 0; i < (1 << n); i++) {
        int s1 = i, num = 0;
        while (s1) {
            num++;
            s1 &= (s1 - 1);
        }
        cnt[i] = num;
        if (!((i << 1) & i || (i >> 1) & i)) st[tot++] = i;
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int now = 0; now < tot; now++) {
            int s1 = st[now];
            for (int pre = 0; pre < tot; pre++) {
                int s2 = st[pre];
                if ((s2 << 1) & s1 || (s2 >> 1) & s1 || s2 & s1) continue;
                for (int j = 0; j <= k; j++) {
                    if (j - cnt[s1] >= 0)
                        dp[i][j][s1] += dp[i - 1][j - cnt[s1]][s2];
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 0; j < tot; j++) {
        ans += dp[n][k][st[j]];
    }
    cout << ans << endl;
}
