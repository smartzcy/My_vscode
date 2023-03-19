#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int a, b, c;
        a = b = c = n / 3;
        int r = n - a - b - c;
        if (r == 0)
            b++, c--;
        else if (r == 1)
            b += 2, c--;
        else if (r == 2)
            b += 2, a++, c--;
        cout << a << " " << b << " " << c << endl;
    }
}