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
        cin >> n >> m;
        if (min(n, m) * 2 >= min(n, m) && (n + m) % 3 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}