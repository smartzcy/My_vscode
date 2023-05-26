#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
const int N = 200005;
int t, n, X1, Y1, X2, Y2;
vector<pi> v[N];
int main() {
    for (scanf("%d", &t); t; --t) {
        int i;
        for (i = 0; i <= 200000; ++i) v[i].clear();
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> X1 >> Y1 >> X2 >> Y2;
            v[X1 + Y1].push_back(pi(X1, X2));
        }
        int flag = 1;
        long long ans = 0;
        for (int i = 0; i <= 200000; ++i) {
            sort(v[i].begin(), v[i].end());
            int R = 0;
            ans += i;
            for (auto &[l, r] : v[i])
                if (l < R)
                    flag = 0, R = max(R, r);
                else
                    ans -= l - R, R = r;
            ans -= i - R;
        }
        puts(flag ? "YES" : "NO");
        cout << ans << endl;
    }
    return 0;
}