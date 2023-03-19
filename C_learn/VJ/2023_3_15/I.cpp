#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int a[N], b[N], c[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int maxx = 0, flag = 1;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) {
            c[i] = a[i] - b[i];
            maxx = max(maxx, c[i]);
            if (c[i] < 0) {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < n && flag; i++) {
            a[i] -= maxx;
            if (a[i] < 0) a[i] = 0;
            if (a[i] != b[i]) {
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
    }
}