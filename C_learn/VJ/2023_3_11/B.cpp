#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
string str[410];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int x1, y1, x2, y2;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            for (int j = 0; j < n; j++) {
                if (str[i][j] == '*') {
                    if (flag == 0) {
                        x1 = i;
                        y1 = j;
                        flag = 1;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        if (x1 == x2) {
            if (x1 == n - 1) {
                str[x1 - 1][y1] = '*';
                str[x2 - 1][y2] = '*';
            } else {
                str[x1 + 1][y1] = '*';
                str[x2 + 1][y2] = '*';
            }
        } else if (y1 == y2) {
            if (y1 == 0) {
                str[x1][y1 + 1] = '*';
                str[x2][y2 + 1] = '*';
            } else {
                str[x1][y1 - 1] = '*';
                str[x2][y2 - 1] = '*';
            }
        } else {
            str[x1][y2] = '*';
            str[x2][y1] = '*';
        }
        for (int i = 0; i < n; i++) cout << str[i] << endl;
    }
}