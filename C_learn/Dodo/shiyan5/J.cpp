#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int a[11][11];
int x[11], y[11];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int maxx = 0;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (maxx < a[i][j]) {
                maxx = a[i][j];
                x[i] = j;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int minn = 1e5;
        for (int j = 0; j < n; j++) {
            if (minn > a[j][i]) {
                minn = a[j][i];
                y[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (y[x[i]] == i) {
            cout << i << " " << x[i] << " " << a[i][x[i]] << endl;
            return 0;
        }
    }
    cout << "No saddle point" << endl;
    return 0;
}