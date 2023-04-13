#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a >= c)
            cout << -1 << " " << b << endl;
        else {
            cout << 1 << " ";
            if (a * b <= c)
                cout << -1 << endl;
            else
                cout << b << endl;
        }
    }
}