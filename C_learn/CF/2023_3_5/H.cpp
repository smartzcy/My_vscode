#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int m, x, y;
string str[3];
int flag[3][N];
bool bfs(int fx, int fy, int nx, int ny) {
    if (nx == 3 && ny == y) return true;
    if (nx <= 0 || nx > 2 || ny <= 0 || ny > m) return false;
    if (flag[nx][ny] == 1) return false;
    flag[nx][ny] = 1;
    bool t;
    if (str[nx][ny] == 'I') {
        if (fx == nx)
            t = bfs(nx, ny, nx, ny + (ny - fy));
        else
            t = bfs(nx, ny, nx + (nx - fx), ny);
    } else {
        if (fy == ny)
            t = bfs(nx, ny, nx, ny - 1) || bfs(nx, ny, nx, ny + 1);
        else
            t = bfs(nx, ny, nx - 1, ny) || bfs(nx, ny, nx + 1, ny);
    }
    flag[nx][ny] = 0;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> x >> y;
        for (int i = 1; i <= m; i++) {
            flag[1][i] = 0;
            flag[2][i] = 0;
        }
        for (int i = 1; i <= 2; i++) {
            cin >> str[i];
            str[i] = " " + str[i];
        }
        if (bfs(0, x, 1, x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 10;
// char g[3][N];
// bool st[3][N];
// int n = 4, m, ex, ey;
// bool dfs(int x, int y, int k) {
//     if (x == 3 and y == ey)
//         return true;
//     if (x < 1 or x > 2 or y < 1 or y > m or st[x][y])
//         return false;
//     st[x][y] = true;
//     bool t;
//     if (g[x][y] == 'I') {
//         if (k == 1)
//             t = dfs(x + 1, y, 1);
//         else if (k == 2)
//             t = dfs(x, y - 1, 2);
//         else if (k == 3)
//             t = dfs(x - 1, y, 3);
//         else
//             t = dfs(x, y + 1, 4);
//     } else {
//         if (k == 1 or k == 3) {
//             t = (dfs(x, y - 1, 2) || dfs(x, y + 1, 4));
//         } else if (k == 2 or k == 4) {
//             t = (dfs(x - 1, y, 3) || dfs(x + 1, y, 1));
//         }
//     }
//     st[x][y] = false;
//     return t;
// }
// void solve() {
//     cin >> m >> ex >> ey;
//     for (int i = 1; i <= 2; i++) {
//         string s;
//         cin >> s;
//         for (int j = 1; j <= m; j++) {
//             st[i][j] = false;
//             g[i][j] = s[j - 1];
//         }
//     }
//     if (dfs(1, ex, 1))
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }
//     return 0;
// }