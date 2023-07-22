#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
const int Mod = 1e9 + 7;
long long n, m, a[N], res[2010][2010], ans;
long long C(long long n, long long m) {
    if (m == 0 || m == n) return 1;
    if (res[n][m] != 0) return res[n][m] % Mod;
    return res[n][m] = (C(n - 1, m) + C(n - 1, m - 1)) % Mod;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        long long res = C(n, i);
        for (int j = 1; j <= m; j++) {
            res *= C(a[j] + n - i - 1, n - i - 1) % Mod;
        }
        if (i & 1)
            ans = (ans - res + Mod) % Mod;
        else
            ans = (ans + res + Mod) % Mod;
    }
    cout << ans << endl;
}