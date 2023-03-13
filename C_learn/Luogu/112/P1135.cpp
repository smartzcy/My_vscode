#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, a, b, ans = 1e9;
int num[N];
bool flag[N];
void dfs(int now, int sum) {
    if (now == b) ans = min(ans, sum);
    if (sum > ans) return;
    flag[now] = 1;
    if (now + num[now] <= n && !flag[now + num[now]]) dfs(now + num[now], sum + 1);
    if (now + num[now] >= 1 && !flag[now - num[now]]) dfs(now - num[now], sum + 1);
    flag[now] = 0;
}
int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    flag[a] = 1;
    dfs(a, 0);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}