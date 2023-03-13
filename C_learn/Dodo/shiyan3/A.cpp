#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    if (n == 1 || n == 3 || n == 5)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}