#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, a[N];
int main() {
    while (cin >> n, n != 0) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], cnt ^= a[i];
        if (cnt == 0)
            cout << 0 << endl;
        else {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if ((cnt ^ a[i]) < a[i]) ans++;
            cout << ans << endl;
        }
    }
}