#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5;
double eqs = 1e-6;
int n, m;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (max(a, max(b, c)) >= a + b + c - max(a, max(b, c))) {
        cout << "Don't make a triangle" << endl;
        return 0;
    }
    int flag1 = 0, flag2 = 0;
    if (a == b && b == c)
        flag1 = 1;
    else if (a == b || b == c || a == c)
        flag1 = 2;
    if (fabs(a * a + b * b - c * c) <= eqs || fabs(a * a + c * c - b * b) <= eqs || fabs(a * a - c * c - b * b) <= eqs)
        flag2 = 1;
    if (flag1 == 1)
        cout << "Equilateral triangle" << endl;
    else if (flag1 == 2 && flag2 == 0)
        cout << "Isosceles triangle" << endl;
    else if (flag2 == 1 && flag1 == 0)
        cout << "Right triangle" << endl;
    else if (flag2 == 1 && flag1 == 2)
        cout << "Isosceles Right triangle" << endl;
    else
        cout << "General triangle" << endl;
}