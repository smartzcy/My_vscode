## 最大下降子序列(洛谷P1020)
```cpp
for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
        if (num[i] < num[j] && dp[i] < dp[j] + 1) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
}
```
上面的方法时间复杂度为：$O(n^2)$   下面考虑优化
记 $f_i$ 表示 对于**所有**长度为$i$的单调不升子序列，它的最后一项的大小 的最大值。特别的，若不存在则 $f_i = 0$。
现在考虑以$i$结尾的单调不升子序列的长度的最大值 $dp_i$。由于我们需要计算所有满足$h(j)>h(i)$的$j$中，$dp_j$的最大值，不妨考虑这个$dp_j$的值是啥。设$dp_j=x$，那么如果$h(j)>f_x$，由于$f_x>=h(j)$，就有$h(i)>h(j)$，矛盾，因此总有$h(i)<=f_x$。
根据刚刚得出的结论，$f_i$单调不增，因此我们要找到尽可能大的$x$满足$h(i)<=f_x$。考虑二分。
绿色区域表示合法的$f_x$(即$f_x>=h(i))$，红色区域表示不合法的$f_x$(即$f_x<h(i)$)，我们需要找到红绿之间的交界点。
假设二分区域$[l,r)$(注意开闭区间。图上黄色区域标出来了二分区域内实际有效的元素)。每次取$m=(l+r)/2$，如果$f_m$在绿色区域内，我们就把$l$移动到此处$(l<-m)$;否则把$r$移动到此处$(r<-m)$。
当$r-l=1$时，$l$处位置即我们需要找的位置。转移$dp_i<-l+1$即可。记得更新$f$。但是我们只能更新$f_{dp_i}$，这是因为$f_1,f_2,···f_{dp_i}$的大小肯定是不小于$h(i)$的。$f_{dp_i}$是最后一个不小于$h(i)$的位置，$f_{dp_i+1}$则小于$h(i)$。
时间复杂度为$O(nlog(n))$

```cpp
    t = 0, memset(F, 0, sizeof(F)), F[0] = INF;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = t + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (F[m] >= H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t) t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
```
### 解答1
```cpp
#include <bits/stdc++.h>
#define up(l, r, i) for (int i = l, END##i = r; i <= END##i; ++i)
#define dn(r, l, i) for (int i = r, END##i = l; i >= END##i; --i)
using namespace std;
typedef long long i64;
const int INF = 2147483647;
const int MAXN = 1e5 + 3;
int n, t, H[MAXN], F[MAXN];
int main() {
    while (~scanf("%d", &H[++n]))
        ;
    --n;
    t = 0, memset(F, 0, sizeof(F)), F[0] = INF;
    up(1, n, i) {
        int l = 0, r = t + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (F[m] >= H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t) t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
    t = 0, memset(F, 0, sizeof(F)), F[0] = 0;
    up(1, n, i) {
        int l = 0, r = t + 1;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (F[m] < H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t) t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
    return 0;
}
```
### 解答2
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll a[maxn], n = 1, dp1[maxn], dp2[maxn], len1, len2;
inline void write(ll x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    while (cin >> a[n]) {
        n++;
    }
    n--, len1 = 1, len2 = 1;
    dp1[1] = a[1], dp2[1] = a[1];
    for (ll i = 2; i <= n; i++) {
        if (a[i] <= dp1[len1]) {
            dp1[++len1] = a[i];
        } else {
            ll k1 = upper_bound(dp1 + 1, dp1 + len1 + 1, a[i], greater<ll>()) - dp1;
            dp1[k1] = a[i];
        }
        if (a[i] > dp2[len2]) {
            dp2[++len2] = a[i];
        } else {
            ll k2 = lower_bound(dp2 + 1, dp2 + len2 + 1, a[i]) - dp2;
            dp2[k2] = a[i];
        }
    }
    write(len1);
    puts("");
    write(len2);
    return 0;
}
```
