#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m, b[N];
long long pre[N], nex[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) pre[i] = 0, nex[i] = 0;
        pre[0] = nex[n + 1] = -INF;
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            pre[i] = max(pre[i - 1], b[i] + i);
        }
        for (int i = n; i >= 1; i--) {
            nex[i] = max(nex[i + 1], b[i] - i);
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, b[i] + pre[i - 1] + nex[i + 1]);
        cout << ans << endl;
    }
}