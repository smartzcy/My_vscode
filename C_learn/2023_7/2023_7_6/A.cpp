#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
const int N = 2e6 + 10;
int n, m;
int a[N], c[N];
vector<int> vec;
int lowbit(int x) {
    return x & -x;
}
void add(int x) {
    for (int i = x; i <= N; i += lowbit(i)) c[i]++;
}
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
int find(int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vec.clear();
        for (int i = 1; i <= n; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vec.push_back(a[i]);
        }
        long long ans = 0;
        sort(vec.begin(), vec.end());
        for (int i = 1; i <= n; i++) {
            int x = find(a[i]);
            ans += sum(vec.size()) - sum(x);
            add(x);
        }
        // for (int i = n; i >= 1; i--) {
        //     int x = find(a[i]);
        //     ans += sum(x) - sum(0);
        //     add(x);
        // }
        cout << ans * 8 << endl;
    }
}