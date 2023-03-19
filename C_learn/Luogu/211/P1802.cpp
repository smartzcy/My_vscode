#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, x;
long long lose[N], win[N], use[N];
long long f[N];
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> lose[i] >> win[i] >> use[i];
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= use[i]; j--) f[j] = max(f[j] + lose[i], f[j - use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; j--) f[j] = f[j] + lose[i];
    }
    cout << f[x] * 5 << endl;
}