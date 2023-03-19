#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, k, dp[N], num = 1;
int sum[N], f[N];
pair<int, int> pa[N];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}
int main() {
    cin >> n >> k;
    for (int i = 1, p, t; i <= k; i++) {
        cin >> p >> t;
        pa[i] = {p, t};
        sum[p]++;
    }
    sort(pa + 1, pa + 1 + k, cmp);
    for (int i = n; i >= 1; i--) {
        if (sum[i] == 0)
            f[i] = f[i + 1] + 1;
        else {
            for (int j = 1; j <= sum[i]; j++) {
                f[i] = max(f[i], f[i + pa[num].second]);
                num++;
            }
        }
    }
    cout << f[1] << endl;
}