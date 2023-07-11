#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
long long n, m[N], k[N], t, ans[N];
double maxx = 0;
struct node {
    long long id, cnt;
} a[N], b[22][N];
bool cmp(const node &A, const node &B) {
    return A.cnt > B.cnt;
}
void dfs() {
    for (long long i = 1; i <= min(20ll, n); i++) {
        long long ans = 0;
        for (long long j = 1; j <= i; j++) ans += b[i][j].cnt;
        if (maxx < 1.0 * ans / i) {
            t = i;
            maxx = 1.0 * ans / i;
        }
    }
    long long ans = 0;
    for (long long i = 1; i <= min(20ll, n); i++) ans += a[i].cnt;
    for (long long i = 21; i <= n; i++) {
        ans += a[i].cnt;
        if (maxx < 1.0 * ans / i) {
            t = i;
            maxx = 1.0 * ans / i;
        }
    }
}
int main() {
    cin >> n;
    for (long long i = 1; i < 200001; i++) {
        a[i].id = i;
        for (long long j = 1; j <= 20; j++) b[j][i].id = i;
    }
    for (long long i = 1; i <= n; i++) {
        cin >> m[i] >> k[i];
        a[m[i]].cnt += k[i];
        for (long long j = 1; j <= 20; j++) b[j][m[i]].cnt += min(j, k[i]);
    }
    sort(a + 1, a + 200001, cmp);
    for (long long i = 1; i <= 20; i++) sort(b[i] + 1, b[i] + 200001, cmp);
    dfs();
    cout << t << endl;
    if (t <= 20) {
        for (long long i = 1; i <= t; i++) ans[i] = b[t][i].id;
    } else {
        for (long long i = 1; i <= t; i++) ans[i] = a[i].id;
    }
    for (long long i = 1; i <= t; i++) cout << ans[i] << " ";
}