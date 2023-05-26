#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, x, y, fa[N];
vector<int> v[N];
inline void DFS(int now) {
    for (int to : v[now])
        if (to != fa[now]) fa[to] = now, DFS(to);
}
int main() {
    cin >> n;
    for (int i = 1; i < n; ++i)
        scanf("%d%d", &x, &y), v[x].push_back(y), v[y].push_back(x);
    DFS(n);
    for (int i = 1; i < n; ++i) cout << fa[i] << " ";
    return 0;
}