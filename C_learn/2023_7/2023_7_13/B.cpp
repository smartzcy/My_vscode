// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 2e5 + 10;
// long long n, m, dp[N];
// pair<long long, long long> a[N];
// bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b) {
//     return a.second < b.second;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         int x, y;
//         cin >> x >> y;
//         a[i] = {x, y};
//     }
//     sort(a + 1, a + 1 + n, cmp);
//     long long ans = dp[1] = a[1].second - a[1].first + 1;
//     for (int i = 2; i <= n; i++) {
//         long long k = 0;
//         for (int j = 1; j < i; j++) {
//             if (a[i].first > a[j].second)
//                 k = max(k, dp[j]);
//         }
//         dp[i] = a[i].second - a[i].first + 1 + k;
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// struct node {
//     int x, y, len;
// } a[150005];
// int dp[150005], ans, k;

// bool cmp(const node &a, const node &b) {
//     return a.y < b.y;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i].x >> a[i].y;
//         a[i].len = a[i].y - a[i].x + 1;
//     }
//     sort(a + 1, a + 1 + n, cmp);
//     ans = dp[1] = a[1].len;
//     for (int i = 2; i <= n; i++) {
//         k = 0;
//         for (int j = 1; j < i; j++)
//             if (a[i].x > a[j].y)
//                 k = max(k, dp[j]);
//         dp[i] = a[i].len + k;
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec[3000010];
int n, mx, dp[3000010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec[y].push_back(x - 1);
        mx = max(mx, y);
    }
    for (int i = 1; i <= mx; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < vec[i].size(); j++) {
            int b = vec[i][j];
            dp[i] = max(dp[i], dp[b] + i - b);
        }
    }
    printf("%d\n", dp[mx]);
    return 0;
}