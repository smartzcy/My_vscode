#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#define int long long
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
vector<int> ji, ou;
vector<int> v;
string s;
signed main() {
    cin >> n;
    m = n;
    for (int i = 1; i <= n; i++) v.push_back(i);
    for (int i = 0; i <= log2(n); i++) {
        ou.clear();
        ji.clear();
        for (auto x : v) {
            cout << "! " << x << " " << i << endl;
            int num;
            cin >> num;
            if (num == 0)
                ou.push_back(x);
            else
                ji.push_back(x);
        }
        v.clear();
        if (ou.size() == m / 2 + 1) {
            s += '1';
            for (auto x : ji) v.push_back(x);
        } else {
            s += '0';
            for (auto x : ou) v.push_back(x);
        }
        m /= 2;
    }
    int ans = 0;
    int num = 1;
    for (auto i : s) {
        ans += num * (i - '0');
        num *= 2;
    }
    cout << "! " << ans << endl;
}