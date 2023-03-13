#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
long long n, c;
long long a[N], b[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) cin >> b[i];
        long long minn = LLONG_MAX;
        long long day = 0;
        long long now = 0;
        for (int i = 1; i <= n; i++) {
            minn = min(minn, day + ((c - now) + a[i] - 1) / a[i]);
            if (i == n) break;
            if (now >= b[i]) {
                now -= b[i];
                day++;
            } else {
                long long x = ((b[i] - now) + a[i] - 1) / a[i];
                now = now + x * a[i] - b[i];
                day += x;
                day++;
            }
        }
        cout << minn << endl;
    }
}