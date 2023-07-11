// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m;
// int val[N];
// vector<int> vec[N];
// void dfs(int u, int fa) {
//     for (auto &v : vec[u]) {
//         if (v == fa) continue;
//         dfs(v, u);
//         val[u] += val[v];
//     }
// }
// int dfs1(int u, int fa) {
//     int maxx = 0, minv = 0, maxv = 0;
//     for (auto &v : vec[u]) {
//         if (v == fa) continue;
//         if (maxx < val[v] - 1) {
//             maxx = val[v] - 1;
//             maxv = v;
//             minv = maxv;
//         } else {
//             minv = v;
//         }
//     }
//     cout << maxx << " " << maxv << endl;
//     if (minv == 0) return maxx;
//     return maxx + dfs1(minv, u);
// }
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n;
//         for (int i = 1; i <= n; i++) {
//             val[i] = 1;
//             vec[i].clear();
//         }
//         for (int i = 1, u, v; i < n; i++) {
//             cin >> u >> v;
//             vec[u].push_back(v);
//             vec[v].push_back(u);
//         }
//         dfs(1, 0);
//         cout << dfs1(1, 0) << endl;
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 3e5 + 10;
int n, m;
vector<int> vec[N], dep[N];
int dfs(int u, int fa, int len) {
    dep[len].push_back(u);
    if (u == 1 && vec[u].size() < 2 || u != 1 && vec[u].size() < 3) {
        return len;
    }
    int ans = n;
    for (auto &v : vec[u]) {
        if (v == fa) continue;
        ans = min(ans, dfs(v, u, len + 1));
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            vec[i].clear();
            dep[i].clear();
        }
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        int len = dfs(1, 0, 1);
        if (len == 1)
            cout << max(n - 2 * len, 0) << endl;
        else {
            int ans = n - 2 * len;
            for (auto &u : dep[len]) {
                if (vec[u].size() == 1) {
                    ans++;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}