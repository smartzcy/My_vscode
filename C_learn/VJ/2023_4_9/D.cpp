#include <bits/stdc++.h>
using namespace std;
long long dp[1 << 10];
signed main() {
    string s;
    cin >> s;
    dp[0]++;
    long long now = 0;
    long long ans = 0;
    for (char c : s) {
        now ^= 1 << (c - '0');
        ans += dp[now]++;
    }
    cout << ans << endl;
    return 0;
}