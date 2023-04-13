#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
vector<string> vec[N];
int main() {
    unordered_map<string, int> map1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string str = "";
        for (int i = 1; i <= m; i++) {
            int num;
            cin >> num;
            str += " " + to_string(num);
        }
        map1[str]++;
    }
    for (auto i : map1) {
        vec[i.second].push_back(i.first);
    }
    cout << map1.size() << endl;
    for (int i = 1e4; i >= 1; i--) {
        for (auto j : vec[i]) {
            cout << i << j << endl;
        }
    }
}