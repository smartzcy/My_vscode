#include <iostream>
#include <algorithm>
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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i + 1] % a[i] == 0) {
                if (a[i] == 1) {
                    if (a[i - 1] == 2)
                        a[i] += 2;
                    else
                        a[i]++;
                    i--;
                } else
                    a[i + 1]++;
            }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
}