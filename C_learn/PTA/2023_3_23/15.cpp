// #include <iostream>
// #include <vector>
// #include "queue"
// #include "string.h"
// #include "set"
// #include <map>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// const int N = 1e5 + 10;
// const int INF = 1e9;
// int n, m, a, b, sum = 0, flag = 1;
// vector<int> vec[N];
// void dfs(int u) {
//     if (vec[u].empty() && u != b) flag = 0;
//     for (auto v : vec[u]) {
//         if (v == b) {
//             sum++;
//         } else {
//             dfs(v);
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> m;
//     for (int i = 1, u, v; i <= m; i++) {
//         cin >> u >> v;
//         vec[u].push_back(v);
//     }
//     cin >> a >> b;
//     dfs(a);
//     cout << sum << " ";
//     if (flag)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;
// }

#include <stdio.h>
#include <iostream>
using namespace std;
int vis[502], path[502], vec[502][502];
int n, m, cnt, a, b;
int DFS(int x) {
    vis[x] = 1;
    if (path[x]) return path[x];
    for (int i = 1; i <= n; i++)
        if (vec[x][i])
            path[x] += DFS(i);
    return path[x];
}
int main() {
    int i;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        vec[a][b] = 1;
    }
    scanf("%d %d", &a, &b);
    path[b] = 1;
    cnt = DFS(a);
    int flag = 1;
    for (i = 1; i <= n; i++) {
        if (vis[i] && !path[i]) {
            flag = 0;
            break;
        }
    }
    printf("%d ", cnt);
    if (!flag)
        printf("No\n");
    else
        printf("Yes\n");
}
