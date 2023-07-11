#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int ans[2005];
int main() {
    int T;
    long long k, v, z;
    scanf("%d", &T);
    while (T--) {
        int tot = 2000, vas = 0;
        v = 0;
        scanf("%lld", &k);
        z = k;
        if (k & 1) {
            printf("-1\n");
            continue;
        }
        do {
            v = 0;
            while (z >= v) {
                if (v)
                    ans[tot + 1] = 0;
                ans[tot] = 1;
                v = 2ll * (v + 1ll);
                tot -= 1;
            }
            tot += 1;
            ans[tot] = 0;
            ans[tot + 1] = 1;
            z -= v / 2 - 1;
        } while (z > 0);
        printf("%d\n", 2000 - tot);
        for (register int i = tot + 1; i <= 2000; i += 1)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}