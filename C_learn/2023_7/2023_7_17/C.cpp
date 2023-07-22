#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m;
int etot = 1;
struct node {
    int y, nxt, id;
} g[N * 2];
int head[N * 2];
void add(int x, int y, int z) {
    g[++etot].y = y;
    g[etot].nxt = head[x];
    g[etot].id = z;
    head[x] = etot;
}
int idx = 0;
int dfn[N], low[N];
vector<long long> BRIDGE;
void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++idx;
    for (int i = head[x]; i; i = g[i].nxt) {
        int y = g[i].y;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) BRIDGE.push_back(g[i].id);
        } else if (i != (in_edge ^ 1))
            low[x] = min(low[x], low[y]);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        add(x, y, i);
        add(y, x, i);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);
    cout << BRIDGE.size() << "\n";
}