#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n >> m;
    cout << boolalpha << (n > m) << endl;
    cout << boolalpha << (n < m) << endl;
    cout << boolalpha << (n == m) << endl;
    cout << boolalpha << (n != m) << endl;
}