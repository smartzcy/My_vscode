#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long num[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    long long ans = 1e9, last = num[0], now = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] - last == 1) {
            now++;
            last = num[i];
        } else {
            ans = min(ans, now);
            last = num[i];
            now = 1;
        }
    }
    cout << ans << endl;
}