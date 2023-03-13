#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    printf("%.2f", a * pow((1 + b / 100.0 / 12), c * 12));
}