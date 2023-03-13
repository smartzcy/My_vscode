#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c)) && a != 0 && b != 0 && c != 0)
        cout << "Invalid" << endl;
    else
        cout << a + b + c << endl;
}