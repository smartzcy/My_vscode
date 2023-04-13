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
        if (n == 1)
            cout << "0" << endl;
        else if (n == 2)
            cout << m << endl;
        else
            cout << (2 * m) << endl;
    }
}