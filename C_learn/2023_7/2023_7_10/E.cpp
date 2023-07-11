#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
long long Map[N], a[N], n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(Map, 0, sizeof(Map));
        long long ma = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            Map[a[i]]++;
            ma = max(ma, a[i]);
        }
        long long up = log2(ma) + 1;
        for (int i = 0; i <= up; i++)
            for (int j = 1; j <= ma + 1; j++)
                if ((j >> i) & 1)
                    Map[j] += Map[j - (1 << i)];
        long long sum = 0;
        for (int i = 1; i <= n; i++) sum += Map[a[i]];
        cout << sum << endl;
    }
    return 0;
}
