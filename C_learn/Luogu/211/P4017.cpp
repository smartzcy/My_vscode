#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;
const int mod = 80112002;
int n, m, ans;
int fa[N];
vector<int> vec[N];
void INIT() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void bfs(int u, int deep) {
    ans = max(deep % mod, ans);
    for (auto v : vec[u]) {
        bfs(v, deep + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    INIT();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        int fu = find(u);
        int fv = find(v);
        vec[v].push_back(u);
        if (fu != fv) {
            fa[fu] = fv;
        }
    }
    for (int i = 1; i <= n; i++)
        if (fa[i] == i) {
            bfs(i, 1);
            break;
        }
    cout << ans << endl;
}