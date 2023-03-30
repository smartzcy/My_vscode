#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << (m / n + 1) * (m / n + 1) * (m % n) + (m / n) * (m / n) * (n - m % n) << endl;
    }
}