#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    cin >> n;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        m += (n / l) * (r - l + 1);
    }
    cout << m << endl;
}