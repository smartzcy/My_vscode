#include <iostream>
#include <algorithm>
using namespace std;
long long n, q, sum;
char ch;
signed main() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        cin >> ch;
        sum += (ch == '+' ? 1 : -1);
    }
    scanf("%lld", &q);
    while (q--) {
        long long x, y, g;
        scanf("%lld%lld", &x, &y);
        if ((n + sum >> 1 < n - sum >> 1) && x > y || x < y && (n + sum >> 1 > (n - sum >> 1))) swap(x, y);
        if (x == y) {
            printf(sum ? "NO\n" : "YES\n");
            continue;
        }
        g = __gcd(x, y), x /= g, y /= g;
        int k = abs(sum) / abs(x - y);
        if (!(sum % (x - y)) && x * k <= (n + sum >> 1) && y * k <= (n - sum >> 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}