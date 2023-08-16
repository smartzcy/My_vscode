#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
long long n, T;
long long a[N];
bool cmp(int x, int y) {
    return x < y;
}
priority_queue<long long> q;
int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        long long tot = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        q.push(tot);
        sort(a + 1, a + n + 1, cmp);
        while (n > 0) {
            long long k = q.top();
            if (k == a[n]) {
                n--;
            } else if (k < a[n]) {
                break;
            } else {
                q.push(k / 2);
                q.push((k + 1) / 2);
            }
            q.pop();
        }
        if (q.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
            while (!q.empty()) {
                q.pop();
            }
        }
    }
    return 0;
}