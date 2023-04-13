#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 5;
int n, m, t;
int i, j, k;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        s = " " + s;
        int len = s.length() - 1;
        long long res = 0, cur = 0;
        for (i = 1; i <= len; i++) {
            if (s[i] == '+')
                cur++;
            else
                cur--;
            if (cur < 0) res += i, cur = 0;
        }
        cout << res + len << endl;
    }
    return 0;
}