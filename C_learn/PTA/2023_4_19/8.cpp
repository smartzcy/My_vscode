#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int a[10005];
int lead(int x) {
    if (a[x] == x)
        return x;
    else
        return a[x] = lead(a[x]);
}
void f(int x, int y) {
    if (lead(x) != lead(y)) a[lead(y)] = lead(x);
}
int main() {
    int n, k, i, sum, t[10005];
    scanf("%d", &n);
    for (i = 1; i < 10003; i++) {
        a[i] = i;
    }
    sum = 0;
    while (n--) {
        scanf("%d", &k);
        for (i = 1; i <= k; i++) {
            scanf("%d", &t[i]);
            if (t[i] > sum) sum = t[i];
        }
        for (i = 2; i <= k; i++) {
            f(t[1], t[i]);
        }
    }
    int buluo = 0;
    for (i = 1; i <= sum; i++) {
        if (a[i] == i) buluo++;
    }
    printf("%d %d\n", sum, buluo);
    int q, x, y;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &x, &y);
        if (lead(x) != lead(y))
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
