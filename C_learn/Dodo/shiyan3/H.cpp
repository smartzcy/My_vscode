#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    double x = b * b - 4 * a * c;
    if (a == 0 && b == 0 && c == 0)
        cout << "Infinitely solution" << endl;
    else if (a == 0 && b == 0)
        cout << "No solution" << endl;
    else if (x == 0) {
        x1 = x2 = -b / (2 * a);
        printf("x1=x2=%.2f", x1);
    } else if (a == 0) {
        printf("x=%.2f", -c / b);
    } else if (x > 0) {
        x1 = (-b + sqrt(x)) / (2 * a);
        x2 = (-b - sqrt(x)) / (2 * a);
        printf("x1=%.2f;x2=%.2f", x1, x2);
    } else {
        cout << "Imaginary root";
    }
}