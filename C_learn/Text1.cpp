#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
int n, m;
int gas[N], cost[N];
int check() {
    int sum = 0, i = 0;
    bool vis[N];
    memset(vis, false, sizeof(vis));
    while (i < n && !vis[i]) {
        vis[i] = true;
        sum = gas[i];
        int pos = i % n;
        while (sum - cost[pos] >= 0) {
            sum += gas[(pos + 1) % n] - cost[pos];
            if (sum < 0) break;
            pos = (pos + 1) % n;
            if (pos == i) return pos;
        }
        i = pos + 1;
    }
    return -1;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> gas[i];
    for (int i = 0; i < n; i++) cin >> cost[i];
    cout << check();
}
