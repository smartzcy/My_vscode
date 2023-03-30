#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 5e5 + 10;
int n, m;
int fa[N], rak[N];
void INIT() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        rak[i] = 0;
    }
}
int find(int x) {
    return fa[x] == x ? x : find(fa[x]);
}
void Insert(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx == yy) return;
    if (rak[xx] < rak[yy]) {
        fa[xx] = yy;
    } else {
        fa[yy] = xx;
        if (rak[xx] == rak[yy]) rak[xx]++;
    }
}
map<int, int> cnt;
int main() {
    cin >> n >> m;
    INIT();
    for (int i = 1, k, u, v; i <= m; i++) {
        cin >> k;
        if (k > 0) cin >> u;
        for (int j = 2; j <= k; j++) {
            cin >> v;
            Insert(u, v);
        }
    }
    for (int i = 1; i <= n; i++) {
        ++cnt[find(i)];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[find(i)] << " \n"[i == n];
    }
}