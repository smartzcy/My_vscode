#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
const int INF = 1e9;
const int N = 5e5 + 10;
int n, q;
int c[N];
vector<int> nums;
vector<array<int, 2>> vs;
vector<array<int, 4>> event;
vector<array<int, 8>> query;
array<int, 4> ans[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x) {
    for (int i = x; i < N; i += lowbit(i)) c[i]++;
}
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
int find(int x) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        vs.push_back({x, y});
        nums.push_back(x);
    }
    for (int i = 1; i <= q; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query.push_back({x2, y2, x1 - 1, y2, x2, y1 - 1, x1 - 1, y1 - 1});
        nums.push_back(x1 - 1);
        nums.push_back(x2);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (auto &xx : vs) {
        int x = xx[0];
        int y = xx[1];
        x = find(x);
        event.push_back({y, -1, -1, x});
    }
    for (int i = 0; i < q; i++) {
        int x1 = query[i][0], y1 = query[i][1];
        int x2 = query[i][2], y2 = query[i][3];
        int x3 = query[i][4], y3 = query[i][5];
        int x4 = query[i][6], y4 = query[i][7];
        x1 = x3 = find(x1);
        x2 = x4 = find(x2);
        event.push_back({y1, i, 0, x1});
        event.push_back({y2, i, 1, x2});
        event.push_back({y3, i, 2, x3});
        event.push_back({y4, i, 3, x4});
    }
    sort(event.begin(), event.end());
    for (auto &xx : event) {
        int y = xx[0];
        int id = xx[1];
        int pos = xx[2];
        int x = xx[3];
        if (id == -1) {
            add(x);
        } else {
            ans[id][pos] = sum(x);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i][0] - ans[i][1] - ans[i][2] + ans[i][3] << endl;
    }
}