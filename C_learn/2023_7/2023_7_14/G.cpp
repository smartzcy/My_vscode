#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    while (cin >> n >> m, n != 0 || m != 0) {
        if (n < m) swap(n, m);
        double b = (sqrt(5.0) + 1.0) / 2.0 * (n - m);
        int a = b;
        if (a == m)
            cout << 0 << endl;
        else {
            cout << 1 << endl;
            int n1 = a + n - m;
            cout << a << ' ' << n1 << endl;
            for (int i = 0; i < m; i++) {
                int k = i * (1 + sqrt(5)) / 2;
                if (m - i == k) {
                    cout << m - i << " " << m << endl;
                    break;
                }
            }
        }
    }
}