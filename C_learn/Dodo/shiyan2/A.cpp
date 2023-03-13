#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    printf("%.4f\n", (cos(50 / 180.0 * 3.1415926535) + sqrt(37.5)) / (n + 1));
}