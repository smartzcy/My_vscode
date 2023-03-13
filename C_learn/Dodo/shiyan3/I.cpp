#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, x, y;
int main() {
    cin >> n >> x >> y;
    cout << n - y / x - (y % x == 0 ? 0 : 1) << endl;
}