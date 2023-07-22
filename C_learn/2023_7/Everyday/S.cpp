#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int beg = 1;
        if (n & 1) {
            beg = 4;
            if (a[1] + a[2] != 0)
                cout << -a[3] << " " << -a[3] << " " << a[1] + a[2] << " ";
            else if (a[2] + a[3] != 0)
                cout << a[2] + a[3] << " " << -a[1] << " " << -a[1] << " ";
            else
                cout << -a[2] << " " << a[1] + a[3] << " " << -a[2] << " ";
        }
        for (int i = beg; i <= n; i += 2) {
            cout << -a[i + 1] << " " << a[i] << " ";
        }
        cout << endl;
    }
}