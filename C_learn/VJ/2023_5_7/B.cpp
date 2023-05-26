#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    char a = str[0];
    for (auto i : str) {
        if (i != a) {
            cout << 2;
            return 0;
        }
    }
    cout << -1;
}
