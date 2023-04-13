#include <iostream>
using namespace std;
int main() {
    int a[20000], n, c = 2, t;
    for (int i = 0; i < 2; i++) cin >> a[i];
    cin >> n;
    for (int i = 0; i < n; i++) {
        t = a[i] * a[i + 1];
        if (t < 10)
            a[c++] = t;
        else {
            a[c++] = t / 10;
            a[c++] = t % 10;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) printf(" ");
    }
    return 0;
}
