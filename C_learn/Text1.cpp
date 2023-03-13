#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5;
int n, m, xc, yc;
vector<double, double> vec[N];
pair<int, int> seg[N];
int main() {
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        seg[i] = {x, y};
    }
    cin >> xc >> yc;
    int xa1, ya1, xb1, yb1, xa2, ya2, xb2, yb2;
    cin >> xa1 >> ya1 >> xb1 >> yb1 >> xa2 >> ya2 >> xb2 >> yb2;
    double d1, d2;
    for (int i = 0; i < n; i++) {
        double d = sqrt((seg[i].first - xc) * (seg[i].first - xc) + (seg[i].second - yc) * (seg[i].second - yc));
        if (d <= d1 && d <= d2) {
            continue;
        } else if (d <= d1) {
            int time1 =
        }
    }
}