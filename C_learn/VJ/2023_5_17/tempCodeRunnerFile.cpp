#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long s = 0;
        bool f = 1;
        for (int i = 1; i <= n - 1; i++) {
            int x;
            cin >> x;
            s += x;
            f &= (s >= i * (i - 1) / 2);
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}