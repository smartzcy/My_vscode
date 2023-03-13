#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n >> m;
    int k = (m / 100 * 60 + m % 100) - (n / 100 * 60 + n % 100);
    cout << (k / 60) << ":" << k % 60;
}