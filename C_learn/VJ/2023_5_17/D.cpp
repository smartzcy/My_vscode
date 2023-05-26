#include <bits/stdc++.h>
using namespace std;
const int mac = 2e5 + 10;
char s[mac];
int a[mac];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    a[1] = 1;
    int ma = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '(') {
            if (s[i - 1] == '(')
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1];
        } else {
            if (s[i - 1] == '(')
                a[i] = a[i - 1];
            else
                a[i] = a[i - 1] - 1;
        }
        ma = max(ma, a[i]);
    }
    int lim = ma;
    ma /= 2;
    ma--;
    ma = lim - ma;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= ma)
            printf("0");
        else
            printf("1");
    }
    printf("\n");
    return 0;
}
