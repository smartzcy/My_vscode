#include <iostream>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5005;

int n, pre[MAXN];
string s;

int f(char ch) {
    if (ch == 'a') return 1;
    if (ch == 'e') return 2;
    if (ch == 'h') return 3;
    if (ch == 'n') return 4;
}

int Hash1(int l, int r) {
    return (pre[r] - pre[l - 1] + MOD) % MOD;
}

int main() {
    cin >> s;
    s = " " + s;
    n = s.length();
    for (int i = 1; i <= n; ++i) {
        pre[i] = (pre[i - 1] * 31 + f(s[i])) % MOD;
    }
    int ans = 0;
    for (int k = 1; k < n; ++k) {
        int sum = 0;
        for (int i = 1; i <= n; i += k) {
            int j = min(i + k - 1, n);
            sum = (sum + Hash1(i, j)) % MOD;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}