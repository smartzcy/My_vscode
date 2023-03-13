#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    if (n < 0)
        cout << n + 1 << endl;
    else if (n < 100)
        cout << n * n * n << endl;
    else
        cout << n * n + 5 << endl;
}