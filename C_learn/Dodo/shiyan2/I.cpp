#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    cout << n / 100 << endl;
    cout << n % 100 / 10 << endl;
    cout << n % 10;
}