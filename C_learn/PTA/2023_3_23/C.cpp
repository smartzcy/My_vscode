#include <stdio.h>
int main() {
    double h, n;
    scanf("%lf%lf", &h, &n);
    double sum = 0;
    if (h == 0 || n == 0)
        printf("0.0 0.0\n");
    else {
        for (int i = 0; i < n; i++) {
            sum += 1.5 * h;
            h /= 2;
        }
        printf("%.1lf %.1lf\n", sum - h, h);
    }
    return 0;
}