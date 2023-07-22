// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 1e5 + 10;
// int n, cnt, d[N];
// vector<int> k[N];
// int main() {
//     cin >> n;
//     for (int i = 1, sz, a; i <= n; i++) {
//         cin >> sz;
//         while (sz--) {
//             cin >> a;
//             k[i].push_back(d[++cnt] = a);
//         }
//     }
//     sort(d + 1, d + 1 + cnt);
//     int pos = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int it : k[i]) {
//             it = lower_bound(d + 1, d + 1 + cnt, it) - d;
//             for (int p = 1; p < k[i].size(); p++) pos += k[i][p - 1] + 1 != k[i][p];
//         }
//     }
//     cout << pos << " " << n + pos - 1 << endl;
// }

#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 5;
int n, cnt, d[N];
vector<int> k[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int sz, a;
        cin >> sz;
        while (sz--) cin >> a, k[i].push_back(d[++cnt] = a);
    }
    sort(d + 1, d + cnt + 1);
    int split = 0;
    for (int i = 1; i <= n; i++) {
        for (int &it : k[i]) it = lower_bound(d + 1, d + cnt + 1, it) - d;
        for (int p = 1; p < k[i].size(); p++) split += k[i][p - 1] + 1 != k[i][p];
    }
    cout << split << " " << n + split - 1 << "\n";
    return 0;
}