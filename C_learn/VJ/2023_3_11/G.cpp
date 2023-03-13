#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
int n, m;
long long d[N], ans[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= N - 10; i++)
        for (int j = 1; j <= (N - 10) / i; j++)
            d[i * j] += i;
    for (long long i = 1; i <= N - 10; i++)
        if (d[i] > N - 10)
            continue;
        else if (ans[d[i]] == 0)
            ans[d[i]] = i;
        else
            ans[d[i]] = min(ans[d[i]], i);
    int T;
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        if (ans[num] == 0)
            cout << -1 << endl;
        else
            cout << ans[num] << endl;
    }
}