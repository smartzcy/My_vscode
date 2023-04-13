#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    cin >> n;
    unordered_map<int, int> map1;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        map1[num]++;
    }
    int ans = 0;
    for (auto i : map1) {
        ans += i.second / 2;
    }
    cout << ans << endl;
}