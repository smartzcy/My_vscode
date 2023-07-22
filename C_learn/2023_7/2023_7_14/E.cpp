#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        int cnt = 0;
        for (int i = 1, a; i <= n; i++) {
            cin >> a;
            if (i % 6 == 0 || i % 6 == 2 || i % 6 == 5) cnt ^= a;
        }
        if (!cnt) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}
/*
1 3 4为最终
*/