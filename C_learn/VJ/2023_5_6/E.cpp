#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
long long g = 1;
long long num[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        g = __gcd(g, num[i]);
    }
}