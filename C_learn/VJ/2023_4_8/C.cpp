#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    cin >> n >> m;
    set<int> s;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        s.insert(num);
    }
    if (m == 0)
        cout << "Yes";
    else {
        bool flag = false;
        for (auto i : s) {
            if (s.find(i - m) != s.end() || s.find(i + m) != s.end()) {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "Yes";
        else
            cout << "No";
    }
}