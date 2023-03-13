#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1e5;
int n, k;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    unordered_map<int, int> map1, map2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        map1[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        map2[b[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (map2[b[i]] != map1[b[i]]) {
        }
    }
}