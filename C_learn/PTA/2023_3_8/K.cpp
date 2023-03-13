#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, m, ans = 0;
vector<int> vec[N];
bool flag[N];
void dfs(int x, int deep) {
    if (deep > ans) {
        ans = deep;
        m = x;
    }
    for (auto i : vec[x]) {
        dfs(i, deep + 1);
    }
}
int main() {
    int nm = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int num;
            cin >> num;
            vec[i].push_back(num);
            flag[num] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!flag[i]) {
            nm = i;
            break;
        }
    dfs(nm, 1);
    cout << m << endl;
}