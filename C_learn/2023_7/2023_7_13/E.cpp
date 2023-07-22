#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, a[N];
struct node {
    int l, r;
    int val;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
    }
}
/*
dp[i] = max(dp[i] , dp[j] + solve(i , j + 1))

solve(i , j + 1) = sum(i , j + 1){
    0:0
    >1 : i - (j + 1) + 1 = i - j;
    <1 : j - i;
}

dp[i] = max(dp[i] , dp[j] + {
    0 : sum(i , j + 1) = 0
    i - j : sum(i , j + 1) > 0
    j - i : sum(i , j + 1) < 0
})
s为前缀
sum(i , j + 1) = s[i] - s[j + 1 - 1] = s[i] - s[j]

dp[i] = max(dp[i] , {
    dp[j] : s[i] == s[j]
    dp[j] - j + i : s[i] > s[j]
    dp[j] + j - i : s[i] < s[j]
})
要去维护 dp[j] dp[j] - j , dp[j] + j的最值
*/