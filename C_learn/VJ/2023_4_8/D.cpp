#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int main() {
    long long a, b, n, m, ans = 4e12;
    cin >> n >> m;
    for (a = 1; a <= n; a++) {
        b = (m + a - 1) / a;
        if (a <= b) {
            if (b <= n) ans = min(ans, a * b);
        } else
            break;
    }
    if (ans == 4e12)
        cout << "-1" << endl;
    else
        cout << ans << endl;
}