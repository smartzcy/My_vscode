#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
long long a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        long long ans = 2e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans = min(ans, a[i]);
        }
        if (a[1] == ans)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
}