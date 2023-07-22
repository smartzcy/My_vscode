#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
vector<int> g[N], seq[N];
int n, root, fa[N], siz[N], ans[N], ned[N];
inline void dfs(int x) {
    siz[x] = 1;
    for (auto t : g[x]) {
        dfs(t);
        siz[x] += siz[t];
        for (auto v : seq[t]) seq[x].push_back(v);
    }
    if (siz[x] <= ned[x]) puts("No"), exit(0);
    seq[x].push_back(x);
    for (int i = siz[x] - 1; i > ned[x]; --i) swap(seq[x][i], seq[x][i - 1]);
    return;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> fa[i];
        cin >> ned[i];
        if (fa[i])
            g[fa[i]].push_back(i);
        else
            root = i;
    }
    dfs(root);
    for (int i = 0; i < n; ++i) ans[seq[root][i]] = i + 1;
    puts("Yes");
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    puts("");
    return 0;
}