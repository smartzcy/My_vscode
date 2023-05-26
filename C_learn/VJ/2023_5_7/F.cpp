#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
double res = 1e-5;
int n, m;
pair<double, double> seg[N];
bool check(double x) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (x > seg[i].second)
            sum += 1;
        else if (x > seg[i].first)
            sum += ((x - seg[i].first) / (seg[i].second - seg[i].first));
    }
    return sum < m;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        seg[i] = {a, b};
    }
    double l = 0, r = 1e9;
    while ((r - l) > res) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}