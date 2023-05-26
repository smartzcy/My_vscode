#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = a[n];
    for (int i = 1; i <= n - 1; i++) res = abs(res - a[i]);
    cout << res;
}