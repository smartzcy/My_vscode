#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 2e5 + 10;
long long n, m = 0;
long long num[N];
int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> num[i];
    }
    sort(num + 1, num + 1 + 2 * n);
    cout << num[n] + num[n + 1];
}