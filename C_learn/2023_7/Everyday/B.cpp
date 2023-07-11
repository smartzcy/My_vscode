#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 5e3 + 10;
int n, m, a[N], v[N];
int sum1[N][N], sum2[N][N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) v[i] = 0;
        for (int i = 1; i <= n; i++) {
            int s = 0;
            for (int j = 1; j <= n; j++) {
                sum1[i][j] = s;
                s += v[j];
            }
            v[a[i]] = 1;
        }
        for (int i = 1; i <= n; i++) v[i] = 0;
        for (int i = n; i >= 1; i--) {
            int s = 0;
            for (int j = 1; j <= n; j++) {
                sum2[i][j] = s;
                s += v[j];
            }
            v[a[i]] = 1;
        }
        long long ans = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                ans += sum1[i][a[j]] * sum2[j][a[i]];
            }
        }
        cout << ans << endl;
    }
}