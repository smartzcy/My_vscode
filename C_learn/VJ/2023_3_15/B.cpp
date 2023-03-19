#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        if (a.length() > b.length()) swap(a, b);
        int n1 = a.length(), n2 = b.length(), x = 0;
        string str = "";
        int flag1 = 0;
        while (x <= n1 * n2) {
            str += a;
            x++;
            int d = 0;
            int flag = 1;
            for (int i = 0; i < str.length(); i++) {
                if (b[d++] != str[i]) {
                    flag = 0;
                    break;
                }
                if (d == n2) d = 0;
            }
            if (flag && d == 0) {
                flag1 = 1;
                break;
            }
        }
        if (flag1)
            cout << str << endl;
        else
            cout << "-1" << endl;
    }
}