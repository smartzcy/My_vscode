// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 5e5 + 10;
// int n, m, d;
// int p[N], a[N];
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n >> m >> d;
//         for (int i = 1; i <= n; i++) cin >> p[i];
//         for (int i = 1; i <= m; i++) cin >> a[i];
//         int last = 1, ans = 0;
//         for (int i = 2; i <= m; i++) {
//             if (p[a[last]] < p[a[i]] && p[a[i]] <= p[a[last]] + d) {
//                 ans += i - last;
//             } else {
//                 last++;
//             }
//         }
//         cout << ans << endl;
//     }
// }
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, d;
int p[N], s[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> d;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            p[num] = i;
        }
        for (int i = 1; i <= m; i++) cin >> s[i];
        int Max = 0, Min = n, flag = 1;
        for (int i = 1; i < m; i++) {
            if (p[s[i]] >= p[s[i + 1]] || p[s[i + 1]] > p[s[i]] + d) {
                flag = 0;
                break;
            }
            Min = min(Min, p[s[i + 1]] - p[s[i]]);
            if (n - 1 > d)
                Max = max(Max, p[s[i + 1]] - p[s[i]]);
        }
        if (!flag)
            cout << 0 << endl;
        else
            cout << min(Min, (d - Max) + 1) << endl;
    }
}