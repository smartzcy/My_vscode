#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m, a[N], b[N];
int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        int count = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            count ^= (b[i] - a[i] - 1);
        }
        if (count == 0)
            cout << "black wins" << endl;
        else
            cout << "white wins" << endl;
    }
}