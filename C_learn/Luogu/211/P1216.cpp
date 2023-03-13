#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
long long num[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long last = 0, last1 = 0;
        for (int j = 1; j <= i; j++) {
            cin >> m;
            last1 = num[j];
            num[j] = max(num[j], last) + m;
            last = last1;
            // cout << num[j] << " ";
        }
        // cout << endl;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, num[i]);
    }
    cout << ans << endl;
}