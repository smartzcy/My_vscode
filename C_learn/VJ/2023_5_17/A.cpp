#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char s[201];
int main() {
    int t, n, i, flag = 0;
    scanf("%d", &t);
    while (t--) {
        flag = 0;
        scanf("%d", &n);
        scanf("%s", s);
        for (i = 0; i < n; i++) {
            if (s[i] == '8') {
                if (n - i >= 11) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}