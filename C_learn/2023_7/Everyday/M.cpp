#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e5 + 10;
PII a[N];
int n, m;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    int w = 0;
    for (int i = 1; i <= n; i++)
        if (m - a[i].first >= 0) {
            m -= a[i].first;
            w++;
        } else
            break;
    int f = 0;
    for (int i = 1; i <= w; i++)
        if (a[i].second == w + 1) {
            f = 1;
            break;
        }
    for (int i = w + 1; i <= n; i++)
        if (a[i].second == w + 1)
            if (m - a[i].first + a[w].first >= 0) {
                f = 1;
                break;
            }
    if (f)
        w++;
    cout << n - w + 1 << '\n';
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}