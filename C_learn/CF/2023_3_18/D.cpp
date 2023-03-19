#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m, x, last_time = 0;
pair<long long, long long> vec[N];
long long dfs(long long nowt, long long l, long long r, long long p) {
    long long ans = 1e5;
    for (long long i = nowt; i <= last_time; i++) {
        auto j = vec[i];
        if (j.first > r || j.second < l) continue;
        if (j.first <= p && j.second >= p)
            return 1;
        else
            ans = min(ans, dfs(i + 1, j.first, j.second, p) + 1);
    }
    return ans;
}
int main() {
    cin >> n >> m >> x;
    for (long long i = 1, t, l, r; i <= n; i++) {
        cin >> t >> l >> r;
        if (vec[i].first == 0)
            vec[i] = {l, r};
        else {
            vec[i].first = min(vec[i].first, l);
            vec[i].second = max(vec[i].second, r);
        }
        last_time = max(last_time, t);
    }
    for (long long i = 1, c, p; i <= m; i++) {
        cin >> c >> p;
        long long ans = dfs(c, p, p, x);
        if (ans >= 1e5)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
}