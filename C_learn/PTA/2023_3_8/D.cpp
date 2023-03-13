#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n >> m;
    cout << (100 * 100 - 100 * m - 100 * (100 - n)) / 2 << endl;
}