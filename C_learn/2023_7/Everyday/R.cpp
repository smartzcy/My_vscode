#include <bits/stdc++.h>
using namespace std;
int n;
string a;
void solve() {
    cin >> n >> a;
    int ind = -1;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '0') {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
        return;
    }
    if (n - ind - 1 >= n / 2) {
        cout << ind + 1 << ' ' << n << ' ' << ind + 2 << ' ' << n << endl;
    } else {
        assert(ind >= n / 2);
        cout << 1 << ' ' << ind + 1 << ' ' << 1 << ' ' << ind << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
