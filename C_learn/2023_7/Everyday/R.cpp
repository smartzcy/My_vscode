#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string str;
        cin >> str;
        int pos1 = -1, pos2 = -1;
        for (int i = 1; i <= n; i++) {
            if (i > n / 2 && str[i - 1] == '0')
                pos2 = i;
            else if (i <= n / 2 && str[i - 1] == '1')
                pos1 = i;
        }
        if (pos2 != -1)
            cout << "1 " << pos2 << " 1 " << pos2 - 1 << endl;
        else if (pos1 != -1)
            cout << pos1 << " " << n << " " << pos1 + 1 << " " << n << endl;
        else if (n & 1)
            cout << "1 " << n / 2 + 1 << " " << n / 2 + 1 << " " << n << endl;
        else
            cout << "1 " << n / 2 << " " << n / 2 + 1 << " " << n << endl;
    }
}