#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define ms(x, n) memset(x, n, sizeof(x));
typedef long long LL;
const int inf = 1 << 30;
const LL maxn = 5 * 1e5 + 10;
int par[maxn], rak[maxn];
void init(int n) {
    for (int i = 1; i <= n; i++)
        par[i] = i, rak[i] = 0;
}
int findr(int x) {
    // 查询树的根
    if (par[x] == x)
        return x;
    else
        return par[x] = findr(par[x]);
}
bool isSame(int x, int y) {
    return findr(x) == findr(y);
}
void unite(int x, int y) {
    x = findr(x);
    y = findr(y);
    if (x == y)
        return;
    if (rak[x] < rak[y])
        par[x] = y;
    else {
        par[y] = x;
        if (rak[x] == rak[y])
            rak[x]++;
    }
}
map<int, int> cnt;
int main() {
    int n, m, k, a, b;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> k;
        if (k > 0) cin >> a;
        for (int j = 2; j <= k; ++j) {
            cin >> b;
            unite(a, b);
        }
    }
    for (int i = 1; i <= n; ++i)
        ++cnt[findr(i)];
    for (int i = 1; i <= n; ++i)
        cout << cnt[findr(i)] << " ";
    cout << endl;
    return 0;
}