#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int mac = 2e5 + 10;
string s;
int a[mac];
int main() {
    int n;
    cin >> n;
    cin >> s;
    s = " " + s;
    a[1] = 1;
    int ma = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '(') {
            if (s[i - 1] == '(')
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1];
        } else {
            if (s[i - 1] == '(')
                a[i] = a[i - 1];
            else
                a[i] = a[i - 1] - 1;
        }
        ma = max(ma, a[i]);
    }
    int lim = ma;
    ma /= 2;
    ma--;
    ma = lim - ma;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= ma)
            cout << '0';
        else
            cout << '1';
    }
    return 0;
}
