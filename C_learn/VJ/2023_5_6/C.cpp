#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m = 1e9, ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        m = min(m, num);
        ans += (m == num);
    }
    cout << ans;
}