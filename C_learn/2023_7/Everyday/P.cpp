#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
int n, m;
struct node {
    int val, id;
    bool operator<(const node &a) const {
        return val < a.val;
    }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        priority_queue<node> que;
        vector<pair<int, int>> ans;
        for (int i = 1, val; i <= n; i++) {
            cin >> val;
            if (val) que.push({val, i});
        }
        while (que.size() >= 2) {
            node a = que.top();
            que.pop();
            node b = que.top();
            que.pop();
            ans.push_back({a.id, b.id});
            if (a.val > 1) que.push({a.val - 1, a.id});
            if (b.val > 1) que.push({b.val - 1, b.id});
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i.first << " " << i.second << endl;
        }
    }
}