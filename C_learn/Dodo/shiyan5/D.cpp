#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int a[N];
int main() {
    while (cin >> n, n != 0) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        if (n % 2 == 1)
            cout << a[n / 2 + 1] << endl;
        else
            cout << (a[n / 2] + a[n / 2 + 1]) / 2 << endl;
    }
}