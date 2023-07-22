#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m;
vector<pair<int, int>> a[N], b[N];
bool check(int x, int y) {
    for (int i = 0; i < n; i++) {
        swap(b[i][x], b[i][y]);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (b[i][j].first < b[i][j - 1].first) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    for (int i = 0; i < n; i++) swap(b[i][x], b[i][y]);
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) a[i].clear(), b[i].clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int c;
                cin >> c;
                a[i].push_back({c, j});
                b[i].push_back({c, j});
            }
        for (int i = 0; i < n; i++) sort(a[i].begin(), a[i].end());
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j].second != j) {
                    if (x == -1) x = j;
                    y = j;
                }
            }
        }
        if (x == -1)
            cout << 1 << " " << 1 << endl;
        else if (check(x, y) == 0)
            cout << x + 1 << " " << y + 1 << endl;
        else
            cout << -1 << endl;
    }
}