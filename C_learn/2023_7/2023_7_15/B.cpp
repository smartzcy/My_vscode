#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
long long n, m, ans;
long long solve(long long n) {
    long long i = 1, tot = 0;
    while (i <= n) {
        int j = n / (n / i);
        tot += n / i * (i + j) * (j - i + 1) / 2;
        i = j + 1;
    }
    return tot;
}
int main() {
    cin >> n >> m;
    cout << solve(m) - solve(n - 1) << endl;
}