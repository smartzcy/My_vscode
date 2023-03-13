#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int sx, sy, fx, fy;
long long n, m, t, cnt = 0;
int num[10][10];
bool flag[10][10];
int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int x, int y) {
    if (x == fx && y == fy) {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + way[i][0];
        ny = y + way[i][1];
        if (flag[nx][ny] || num[nx][ny] || nx <= 0 || y <= 0 || x > n || y > m) continue;
        flag[nx][ny] = 1;
        dfs(nx, ny);
        flag[nx][ny] = 0;
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1, x, y; i <= t; i++) {
        cin >> x >> y;
        num[x][y] = 1;
    }
    dfs(sx, sy);
    cout << cnt << endl;
}