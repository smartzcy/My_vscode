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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            int l = 1, r = i;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (a[mid] >= i - mid + 1)
                    r = mid;
                else
                    l = mid + 1;
            }
            cout << i - l + 1 << " ";
        }
        cout << endl;
    }
}