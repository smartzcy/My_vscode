#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, x, y;
int way[9][2] = {{0, 0}, {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {-1, 2}, {-1, -2}};
long long num[25][25];
long long f[25][25];
int main() {
    cin >> n >> m;
    cin >> x >> y;
    x += 2, y += 2, n += 2, m += 2;
    f[2][1] = 1;
    for (int i = 0; i < 9; i++) {
        int xx = x + way[i][0];
        int yy = y + way[i][1];
        num[xx][yy] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (num[i][j]) continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    cout << f[n][m] << endl;
}