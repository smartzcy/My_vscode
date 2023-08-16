/*
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100 + 10;
int mp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int flag = 0;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mp[i][j] = 0;
        while (m--) {
            int u, v;
            cin >> u >> v;
            if (u == v)
                flag = 1;
            mp[u][v] = 1;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    mp[i][j] |= mp[i][k] & mp[k][j];
        int in[N], out[N];
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] == 1 && mp[j][i] == 1)
                    flag = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && mp[i][j]) {
                    ++in[j], ++out[i];
                }
        int ans = 0;
        if (flag) {
            for (int i = 1; i <= n; i++)
                cout << 0;
            cout << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            if ((in[i] > n / 2 || out[i] > n / 2))
                cout << 0;
            else
                cout << 1;
        cout << endl;
    }
    return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
int main() {
    for (long long a = 1; a <= 10; a++) {
        for (long long p = 1; p <= 16; p++) {
            cout << a << " " << p << endl;
            long long ans = 0;
            for (long long x = 1; x <= pow(2, p); x++) {
                if (((long long)pow(a, x) % (long long)pow(2, p)) == ((long long)pow(x, a) % ((long long)pow(2, p)))) ans++;
            }
            cout << ans << endl;
        }
    }
}