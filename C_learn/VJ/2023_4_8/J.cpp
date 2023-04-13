#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << (n + 1) / 2 << endl;
        for (int i = 1; i <= (n + 1) / 2; i++) {
            cout << 3 * i - 1 << " " << (n - i + 1) * 3 << endl;
        }
    }
}