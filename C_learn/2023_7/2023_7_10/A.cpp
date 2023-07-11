#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int dp[410][22];
bool check(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] && (x & (1 << j)) && (x & (1 << i))) return 0;
        }
    }
    return 1;
}
int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        u--, v--;
        dp[u][v] = dp[v][u] = 1;
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (check(i)) ans++;
    }
    cout << ans << endl;
}