#include <bits/stdc++.h>
using namespace std;
int q[5];
int a[7] = {0, 4, 8, 15, 16, 23, 42};
int main() {
    for (int i = 1; i <= 4; i++) {
        printf("? %d %d\n", i, i + 1);
        fflush(stdout);
        int x;
        scanf("%d", &x);
        q[i] = x;
    }
    do {
        if (a[1] * a[2] == q[1] && a[2] * a[3] == q[2] && a[3] * a[4] == q[3] && a[4] * a[5] == q[4]) {
            printf("!");
            for (int i = 1; i <= 6; i++)
                printf(" %d", a[i]);
            puts("");
            break;
        }
    } while (next_permutation(a + 1, a + 7));
    return 0;
}
