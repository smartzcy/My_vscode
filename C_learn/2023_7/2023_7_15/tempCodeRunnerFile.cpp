#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n >= m)
            cout << n - m << endl;
        else {
            long long ans = INF;
            for (int l = 1, r; l <= n; l = r + 1) {
                r = min(n, (m - 1) / ((m - 1) / r));
                ans = min(ans, (m - 1) / l * l);
            }
            cout << ans + n - m << endl;
        }
    }
}