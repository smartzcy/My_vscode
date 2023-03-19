#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
const int M = 1e7 + 10;
int t, m;
long long v[N], w[N], f[M];
int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++)
        for (int j = w[i]; j <= t; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[t] * 5 << endl;
}