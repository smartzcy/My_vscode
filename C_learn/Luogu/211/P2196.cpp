#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e3;
int n, m, cnt;
int a[N], g[N][N];
int ans[N], fa[N];
vector<int> vec;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            if (g[j][i] && ans[j] > ans[i]) {
                ans[i] = ans[j];
                fa[i] = j;
            }
        ans[i] += a[i];
        if (ans[i] > cnt) {
            cnt = ans[i];
            m = i;
        }
    }
    while (m != fa[m]) {
        vec.push_back(m);
        m = fa[m];
    }
    for (int i = vec.size() - 1; i >= 0; i--) cout << vec[i] << " ";
    cout << endl;
    cout << cnt << endl;
}