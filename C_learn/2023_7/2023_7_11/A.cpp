#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
double n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    double ans = 0;
    for (double i = 1; i <= n; i++) {
        ans += i * (pow(i / n, m) - pow((i - 1) / n, m));
    }
    cout << ans << endl;
}