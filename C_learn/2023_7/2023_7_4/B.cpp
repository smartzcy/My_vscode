#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long a, b, n, m, h;
bool check(int x) {
    int num1 = n / b;
    int num = num1 * (h - a);
    int l = x - num1 * b;
    int num2 = l / b;
    num += num2 * (h - b);
    if (num >= n + m - x) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> n >> m >> h;
        long long l = n + 1, r = n + m;
        while (l <= r) {
            long long mid = l + r >> 1;
            if (check(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << r + 1 << endl;
    }
    return 0;
}