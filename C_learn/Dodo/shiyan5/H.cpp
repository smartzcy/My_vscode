#include <iostream>
using namespace std;
int a[11][11];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (a[i][j] != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}