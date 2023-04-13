#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    vector<string> a;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<string> a;
        for (int i = 1; i <= 2 * n - 2; i++) {
            string s;
            cin >> s;
            if (s.size() == n / 2) a.push_back(s);
        }
        reverse(a[1].begin(), a[1].end());
        if (a[0] == a[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}