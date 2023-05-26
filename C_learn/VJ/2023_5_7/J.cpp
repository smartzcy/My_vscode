#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;
long long f[N][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    f[2][1] = 1;
    f[2][2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i][0] = (f[i - 1][1] + f[i - 1][2]) % mod;
        f[i][1] = (f[i - 2][0] + f[i - 2][1]) % mod;
        f[i][2] = (f[i - 2][0] + f[i - 2][2]) % mod;
    }
    cout << f[n][1];
}
