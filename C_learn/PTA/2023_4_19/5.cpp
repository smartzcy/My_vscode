#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
struct node {
    int p, index;
};
int n, k, x, pre[N], root;
queue<node> q;
double z, r, sum;
int deal() {
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        int cnt = 0, a = u.index;
        while (pre[a] != a) {
            a = pre[a];
            cnt++;
        }
        sum += z * pow(1 - r / 100, cnt) * u.p;
    }
    return (int)sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> z >> r;
    for (int i = 0; i < n; i++) pre[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (!k) {
            cin >> x;
            q.push({x, i});
        }
        while (k--) {
            cin >> x;
            pre[x] = i;
        }
    }
    cout << deal();
}
