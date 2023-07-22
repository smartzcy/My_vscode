#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string str;
        cin >> str;
        int tot = 1;
        vector<int> res = {1};
        for (int i = 1; i < n - 1; i++) {
            if (str[i] == str[i - 1])
                tot++;
            else
                tot = 1;
            res.push_back(i + 2 - tot);
        }
        for (int i = 0; i <= n - 2; i++) {
            cout << res[i] << " \n"[i == n - 2];
        }
    }
}