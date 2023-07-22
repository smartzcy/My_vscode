// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, k, ans;
// int main() {
//     cin >> n >> k;
//     for (int l = 1, r; l <= k; l = r + 1) {
//         r = k / (k / l);
//         ans -= (k / l) * (r - l + 1);
//     }
//     cout << ans << endl;
//     ans += k * n;
//     cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = n * k;
    for (long long l = 1, r; l <= n; l = r + 1) {
        if (l > k) break;
        r = min(k / (k / l), n);
        ans -= (k / l) * (l + r) * (r - l + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
