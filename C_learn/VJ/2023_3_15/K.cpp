#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int s[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        string str;
        cin >> str;
        for (int i = 1; i <= n; i++) {
            s[i] = (str[i - 1] == 'B' ? 0 : 1);
            s[i] += s[i - 1];
        }
        int ans = 1e9;
        for (int i = m; i <= n; i++) {
            ans = min(ans, s[i] - s[i - m]);
        }
        cout << ans << endl;
    }
}