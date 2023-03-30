#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int num[1000];
int n, k;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> num[i];
    sort(num + 1, num + n + 1, greater<int>());
    cout << num[k] << endl;
}