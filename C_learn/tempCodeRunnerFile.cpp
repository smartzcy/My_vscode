#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m;
vector<pair<int, char>> adj[N];
int dis[N];
int pre[N];
bool vis[N];
vector<int> road;
vector<char> ans;
void bfs(int st) {
    vis[st] = 1;
    queue<pair<int, int>> q;
    q.push({st, 0});
    dis[st] = 0;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        int from = now.first;
        for (auto i : adj[from]) {
            int v = i.first;
            if (!vis[v]) {
                dis[v] = now.second + 1;
                vis[v] = 1;
                q.push({v, dis[v]});
            }
        }
    }
}
void search(int st) {
    vector<int> vec;
    vec.push_back(st);
    for (int i = 0; i < dis[1]; i++) {
        vector<int> add;
        int minn = 1000;
        for (auto u : vec) {
            for (auto v : adj[u]) {
                if (dis[v.first] + 1 == dis[u]) {
                    minn = min(minn, (int)(v.second));
                }
            }
        }
        for (auto u : vec) {
            for (auto v : adj[u]) {
                if (dis[v.first] + 1 == dis[u] && v.second == minn && !vis[v.first]) {
                    pre[v.first] = u;
                    add.push_back(v.first);
                    vis[v.first] = 1;
                }
            }
        }
        vec.clear();
        vec = add;
        ans.push_back(char(minn));
    }
}
void output(int st) {
    if (pre[st] != 0)
        output(pre[st]);
    cout << st << " ";
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        adj[u].push_back({v, ch});
        adj[v].push_back({u, ch});
    }
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    bfs(n);
    memset(vis, 0, sizeof(vis));
    search(1);
    cout << dis[1] << endl;
    output(n);
    cout << endl;
    for (auto i : ans) {
        cout << i;
    }
}