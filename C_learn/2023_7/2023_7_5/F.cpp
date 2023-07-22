#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m, len, top, opt, x, y;
int k[200200], f[200200], g[200200], l[200200], r[200200], pos[200200];
int main() {
    scanf("%d", &n);
    len = sqrt(n);
    for (int i = 0; i < n; i++) scanf("%d", &k[i]), pos[i] = i / len + 1, l[pos[i]] = 2147483647;
    for (int i = 0; i < n; i++) l[pos[i]] = min(l[pos[i]], i), r[pos[i]] = max(r[pos[i]], i), top = max(pos[i], top);
    for (int i = n - 1; i >= 0; i--) {
        if (i + k[i] > r[pos[i]]) {
            f[i] = 1;
            g[i] = i + k[i];
        } else {
            f[i] = f[i + k[i]] + 1;
            g[i] = g[i + k[i]];
        }
    }
    scanf("%d", &m);
    while (m-- > 0) {
        scanf("%d%d", &opt, &x);
        if (opt == 1) {
            int res = 0;
            while (g[x] < n) {
                res += f[x];
                x = g[x];
            }
            res += f[x];
            printf("%d\n", res);
        } else {
            scanf("%d", &y);
            k[x] = y;
            for (int i = r[pos[x]]; i >= l[pos[x]]; i--) {
                if (i + k[i] > r[pos[i]]) {
                    f[i] = 1;
                    g[i] = i + k[i];
                } else {
                    f[i] = f[i + k[i]] + 1;
                    g[i] = g[i + k[i]];
                }
            }
        }
    }
    return 0;
}