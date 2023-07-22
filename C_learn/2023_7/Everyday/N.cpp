#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m;
long long get(vector<long long> a) {
    long long res = 0;
    multiset<long long> s;
    long long cnt = 0;
    for (auto x : a) {
        res += x;
        s.insert(x);
        while (res < 0) {
            res -= 2 * (*s.begin());
            cnt++;
            s.erase(s.begin());
        }
    }
    return cnt;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<long long> a(n), b, c;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = m; i < n; i++) b.push_back(a[i]);
        for (int i = m - 1; i > 0; i--) c.push_back(-a[i]);
        cout << get(b) + get(c) << endl;
    }
}