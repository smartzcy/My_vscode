#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n > 9999) {
        printf("%d-%02d", n / 100, n % 100);
    } else {
        if (n / 100 < 22)
            printf("20%02d-%02d", n / 100, n % 100);
        else
            printf("19%02d-%02d", n / 100, n % 100);
    }
    return 0;
}