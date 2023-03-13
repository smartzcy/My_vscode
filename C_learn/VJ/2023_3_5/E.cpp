#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N];
bool f[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = 0;
        }
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i - a[i] - 1 >= 0) f[i] |= f[i - a[i] - 1];
            if (i + a[i] <= n) f[i + a[i]] |= f[i - 1];
        }
        cout << (f[n] ? "YES" : "NO") << endl;
    }
}