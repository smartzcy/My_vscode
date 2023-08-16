#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, k;
int add[N], a[N];
int ask(int i, int j, int x) {
    if (x == 1)
        cout << "or " << i << " " << j << endl;
    else
        cout << "and " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main() {
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        add[i] = ask(1, i, 1) + ask(1, i, 2);
    }
    a[1] = (add[3] + add[2] - ask(2, 3, 1) - ask(2, 3, 2)) / 2;
    for (int i = 2; i <= n; i++) {
        a[i] = add[i] - a[1];
    }
    sort(a + 1, a + 1 + n);
    cout << "finish " << a[k] << endl;
}