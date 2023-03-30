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
        string str;
        cin >> str;
        int ans1 = 1, ans2 = 1;
        int flag = 0, pre = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'N') {
                if (pre) ans1 = ans2 = 0;
                flag = pre = 1;
            } else {
                if (i == 0) ans2 = 0;
                pre = 0;
            }
        }
        if (!flag) ans1 = 0;
        cout << ans1 << " " << ans2 << endl;
    }
}