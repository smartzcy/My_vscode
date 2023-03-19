#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        if (a[0] + a[1] <= m || a[n - 1] <= m)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}