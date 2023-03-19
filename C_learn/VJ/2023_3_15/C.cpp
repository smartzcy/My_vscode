#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int sum = 2 * n - 2 * m + 1;
        for (int i = 1; i <= n - sum; i++) cout << i << " ";
        for (int i = m; i > n - sum; i--) cout << i << " ";
        cout << endl;
    }
}