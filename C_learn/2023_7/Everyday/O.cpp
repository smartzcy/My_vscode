#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 3e5 + 10;
int n, m;
long long a[N];
long long check(long long maxx) {
    long long res = 0;
    long long odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (maxx - a[i] & 1) {
            odd++;
        }
        even += (maxx - a[i]) / 2;
    }
    if (even > odd) {
        long long sub = (even - odd + 1) / 3;
        odd += sub * 2;
        even -= sub;
    }
    long long sub = min(odd, even);
    res = sub * 2;
    odd -= sub;
    even -= sub;
    if (odd)
        res += odd * 2 - 1;
    else if (even)
        res += even * 2;
    return res;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        long long maxx = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], maxx = max(maxx, a[i]);
        cout << min(check(maxx), check(maxx + 1)) << endl;
    }
}