#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
const int N = 3e5 + 10;
int n, m, s, t;
int a[N], pre[N], nex[N];
int vis[N], vis2[N];
int low[N];
vector<int> prime;
vector<int> vec[N];
void getPrime() {
    low[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!low[i]) {
            for (int j = i; j < N; j += i) {
                low[j] = i;
            }
        }
    }
}
void solve() {
    queue<int> que;
    vis[s] = 1;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        int x = a[u];
        while (x != 1) {
            int v = low[x];
            if (!vis2[v]) {
                vis2[v] = 1;
                for (int y : vec[v]) {
                    if (!vis[y]) {
                        pre[y] = u;
                        vis[y] = 1;
                        que.push(y);
                        if (y == t) {
                            vector<int> ans;
                            ans.push_back(t);
                            while (pre[y]) {
                                ans.push_back(pre[y]);
                                y = pre[y];
                            }
                            reverse(ans.begin(), ans.end());
                            cout << ans.size() << endl;
                            for (auto nm : ans) cout << nm << " ";
                            return;
                        }
                    }
                }
            }
            x /= low[x];
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    getPrime();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        while (x != 1) {
            vec[low[x]].push_back(i);
            x /= low[x];
        }
    }
    cin >> s >> t;
    if (s == t)
        cout << 1 << endl
             << s << endl;
    else if (__gcd(a[s], a[t]) != 1) {
        cout << 2 << endl
             << s << " " << t << endl;
    } else {
        solve();
    }
}