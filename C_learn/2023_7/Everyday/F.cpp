#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        if (a == 1) {
            cout << ((n - 1) % b ? "No" : "Yes") << endl;
            continue;
        }
        long long ans = 1;
        bool flag = 0;
        while (ans <= n) {
            if ((n - ans) % b == 0) {
                flag = 1;
                break;
            }
            ans *= a;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}