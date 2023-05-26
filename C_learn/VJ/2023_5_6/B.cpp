#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    cin >> n >> m;
    if (n < m) {
        n += m;
        m = n - m;
        n = n - m;
    }
    for (int i = 1; i <= n; i++) cout << m;
}