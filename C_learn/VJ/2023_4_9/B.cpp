#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n, m, p[100][100];
char k[100][100];
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("\n");
        for (int j = 1; j <= m; ++j) scanf("%c", k[i] + j);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (k[i][j] >= '0' && k[i][j] <= '9') {
                int t = k[i][j] - '0';
                for (int x = -t; x <= t; ++x)
                    for (int y = abs(x) - t; y <= t - abs(x); ++y) p[max(min(i + x, n), 1ll)][max(min(j + y, m), 1ll)] = -1;
            }
            if (p[i][j] == -1)
                continue;
            else if (k[i][j] == '#')
                p[i][j] = 1;
            else
                p[i][j] = -1;
        }
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= m; ++j) {
            if (p[i][j] == 1)
                printf("#");
            else
                printf(".");
        }
    return 0;
}