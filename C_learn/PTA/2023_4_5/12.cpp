#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
const int maxn = 10001;
vector<int> v[maxn];
vector<int> temp;
int t[maxn];
void Dfs(int index, vector<int> &p) {
    if (p.size() > temp.size()) {
        temp.clear();
        temp = p;
    }
    for (int i = 0; i < v[index].size(); i++) {
        p.push_back(v[index][i]);
        Dfs(v[index][i], p);
        p.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            v[i].push_back(x);
            t[x] = 1;
        }
        if (v[i].size()) {
            sort(v[i].begin(), v[i].end());
        }
    }
    for (int i = 0; i < n; i++) {
        if (!t[i]) {
            vector<int> p;
            p.push_back(i);
            Dfs(i, p);
            break;
        }
    }
    cout << temp.size() << endl;
    for (int i = 0; i < temp.size(); i++) {
        if (!i)
            cout << temp[i];
        else
            cout << " " << temp[i];
    }
}
