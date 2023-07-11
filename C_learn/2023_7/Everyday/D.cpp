// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, m;
// int a[N];
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n;
//         int sum1 = 0, sum2 = 0;
//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//             sum1 ^= a[i];
//             sum2 += a[i];
//         }
//         if (sum1 * 2 == sum2)
//             cout << "0" << endl, cout << endl;
//         else if (sum1 == sum2) {
//             cout << 2 << endl;
//             cout << sum2 / 2 << " " << sum2 / 2 << endl;
//         } else if (sum1 == 0) {
//             cout << 3 << endl;
//             cout << sum2 << " " << 3 * sum2 << " " << sum2 << endl;
//         } else {
//             cout << 2 << endl;
//             cout << sum1 << " " << sum2 + sum1 << endl;
//         }
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        long long ans = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> m;
            ans ^= m;
            sum += m;
        }
        cout << 2 << endl
             << ans << " " << (ans + sum) << endl;
    }
}