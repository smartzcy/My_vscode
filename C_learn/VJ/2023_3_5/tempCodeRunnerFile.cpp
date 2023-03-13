#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long a[N], b1[N], b2[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) b1[i] = max(0ll, a[i - 1] - a[i]);
    for (int i = n - 1; i >= 1; i--) b2[i] = max(0ll, a[i + 1] - a[i]);
    while (m--) {
        long long x, y;
        cin >> x >> y;
        if (x < y)
            cout << b1[y] - b1[x] << endl;
        else
            cout << b2[y] - b2[x] << endl;
    }
}