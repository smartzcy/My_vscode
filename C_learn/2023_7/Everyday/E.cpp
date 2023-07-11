#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, m;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a[1];
        long long res = a[1], cnt = 0, ans = 1;
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            res &= a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == res) cnt++;
        }
        ans = ans * cnt * (cnt - 1) % mod;
        for (int i = 1; i <= n - 2; i++) ans = ans * i % mod;
        cout << ans << endl;
    }
}