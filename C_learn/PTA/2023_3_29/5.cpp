#include <iostream>
using namespace std;
int main() {
    int a[6], b[6] = {0}, i, n, j, t;
    for (i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            if (i == 0) {
                if (a[j] != 6)
                    a[j] = 6;
                else
                    a[j]--;
            } else if (i != 0) {
                if (a[j] - 1 == b[j])
                    a[j] = a[j] - 2;
                else
                    a[j]--;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (i < 5)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
    return 0;
}
