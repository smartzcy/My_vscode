#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long a, b, n, m, h;
bool check(int x) {
    if (x <= n) return 0;
    int s1 = n / b * (b - a);
    int s2 = x / b * (h - b);
    if (s1 + s2 < n + m - x) return 0;
    return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &a, &b, &n, &m, &h);
        int l = 1, r = n + m + 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l);
    }
}