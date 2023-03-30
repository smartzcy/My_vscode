#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e2 + 10;
int n, m;
int a[N][N];
int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i <= n; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= n - 1; j++) {
            int flag = 0;
            for (int k = 0; k < 4; k++) {
                if (abs(a[i][j] - a[i + way[k][0]][j + way[k][1]]) >= 50) flag++;
            }
            if (flag == 4) sum++;
        }
    }
    cout << sum << endl;
}