#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e3 + 10;
long long n, m;
int main() {
    cin >> n >> m;
    int cnt = 0;
    for (long long i = 1, a; i <= n; i++) {
        cin >> a;
        if (m % 2 == 0) {
            if ((a - m) % (m + 1) == 0)
                cnt ^= 2;
            else
                cnt ^= !(((a + 1) % (m + 1)) % 2);
        } else {
            cnt ^= a % 2;
        }
    }
    if (!cnt)
        cout << "BAD" << endl;
    else
        cout << "GOOD" << endl;
}
/*
m % 2 == 0
2 : m + (m + 1)k
(n + 1) % (m + 1) % 2 ? 0 : 1

m % 2 == 1
n % 2
*/