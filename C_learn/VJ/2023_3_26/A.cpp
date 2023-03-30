#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int flag = 0;
        cin >> n;
        string str;
        cin >> str;
        for (int i = 0; i < n; i++) {
            if (str[i] == '8') {
                if (n - i >= 11) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}