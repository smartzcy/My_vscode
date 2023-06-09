#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], f[1 << 22];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[a[i]] = a[i];
    }
    for (int i = 0; i <= 21; i++)
        for (int j = 0; j < (1 << 22); j++)
            if ((j & (1 << i)) && f[j ^ (1 << i)]) f[j] = f[j ^ (1 << i)];
    for (int i = 1; i <= n; i++) {
        int b = ((1 << 22) - 1) ^ a[i];
        printf("%d ", f[b] ? f[b] : -1);
    }
}
