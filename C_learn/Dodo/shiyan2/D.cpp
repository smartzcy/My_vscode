#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << endl;
    printf("%.5f\n", (a + b + c) / 3.0);
    cout << min(a, min(b, c)) << endl;
    cout << max(a, max(b, c)) << endl;
}