#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int num;
        if (a[0] == a[1])
            num = a[0];
        else
            num = a[2];
        for (int i = 0; i < n; i++) {
            if (a[i] != num) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}