# 数位DP

## 适用问题

1. 要求统计满足一定条件的数的数量（即，最终目的为计数）
2. 这些条件经过转化后可以使用 **$[数位]$** 的思想去理解和判断
3. 输入会提供一个数字区间（有时也只提供上界）来作为统计的限制
4. 上届很大（比如 $ 10^{18}$），暴力枚举验证会超时。

## 模板（DFS）

```cpp
ll dfs(int pos, int limit, int zero, 状态) {
    // 可以根据题意进行灵活剪枝

    if (!pos) {
        边界的判断条件
    }
    if (!limit && !zero && dp[pos][状态] != -1) return dp[pos][状态];
    ll res = 0;
    int end = limit ? a[pos] : 进制 - 1;
    for (int i = 0; i <= end; ++i)
        res += dfs(pos - 1, limit && i == end, zero && i == 0, 状态更新);
    if (!limit && !zero) dp[pos][状态] = res;
    return res;
}
ll dp(ll x) {
    memset(dp, -1, sizeof dp);
    int len = 0;
    while (x) a[++len] = x % 进制, x /= 进制; // 可以len++ ,看个人习惯
    return dfs(len, 1, 1, 状态);
}
int main() {
    ll l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;
    return 0;
}
```

