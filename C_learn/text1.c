#include <stdio.h>
int main() {
    int a[10] = {1, 2, 3};
    printf("%d\n", a[0]);
    *a = 2;
    printf("%d\n", a[0]);
    *(a + 1) = 5;
    printf("%d\n", a[1]);
}