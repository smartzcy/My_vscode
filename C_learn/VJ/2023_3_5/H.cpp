#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int a[5];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, num = 0;
        cin >> x;
        for (int i = 1; i <= 3; i++) cin >> a[i];
        while (x) {
            num++;
            x = a[x];
        }
        if (num == 3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}