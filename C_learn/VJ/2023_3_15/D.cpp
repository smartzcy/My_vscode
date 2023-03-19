#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e9;
int n, m;
int a[N];
int sum[N], mx1[N], mx2[N], mn1[N], mn2[N];
int chk(int x, int y) {
    if (x <= 0 && y >= 0)
        return 0;
    else
        return 1;
}
int solve(int x, int y, int x2, int y2) {
    if (x > x2) swap(x, x2), swap(y, y2);
    if (x2 > y) return (y - x + 1) + (y2 - x2 + 1) + (chk(x, y) & chk(x2, y2));
    return max(y, y2) - min(x, x2) + 1 + chk(min(x, x2), max(y, y2));
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        string str;
        cin >> str;
        sum[0] = 0, mx1[0] = -inf, mx2[n + 1] = -inf, mn1[0] = inf, mn2[n + 1] = inf;
        for (int i = 1; i <= n; i++) {
            a[i] = (str[i - 1] == '+' ? 1 : -1);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            mx1[i] = max(mx1[i - 1], sum[i]);
            mn1[i] = min(mn1[i - 1], sum[i]);
        }
        for (int i = n; i >= 1; i--) {
            mx2[i] = max(mx2[i + 1], sum[i]);
            mn2[i] = min(mn2[i + 1], sum[i]);
        }
        while (m--) {
            int l, r;
            cin >> l >> r;
            if (l == 1 && r == n)
                cout << 1 << endl;
            else if (l == 1)
                cout << (mx2[r + 1] - mn2[r + 1] + 1) + chk(mn2[r + 1] - (sum[r] - sum[l - 1]), mx2[r + 1] - (sum[r] - sum[l - 1])) << endl;
            else if (r == n)
                cout << (mx1[l - 1] - mn1[l - 1] + 1) + chk(mn1[l - 1], mx1[l - 1]) << endl;
            else {
                int x = mn1[l - 1], y = mx1[l - 1];
                int x2 = mn2[r + 1] - (sum[r] - sum[l - 1]), y2 = mx2[r + 1] - (sum[r] - sum[l - 1]);
                cout << solve(x, y, x2, y2) << endl;
            }
        }
    }
}