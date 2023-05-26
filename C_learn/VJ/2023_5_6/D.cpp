#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int a[10][10];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[to_string(i)[0] - '0'][i % 10]++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ans += a[i][j] * a[j][i];
    cout << ans;
}