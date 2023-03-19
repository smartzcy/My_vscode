#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int s[N], f[N], d[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int last = 0;
        queue<int> que;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            que.push(s[i]);
        }
        for (int i = 0; i < n; i++) cin >> f[i];
        for (int i = 0; i < n; i++) {
            last = max(last, que.front());
            que.pop();
            d[i] = f[i] - last;
            last = f[i];
        }
        for (int i = 0; i < n; i++) cout << d[i] << " \n"[i == n - 1];
    }
}