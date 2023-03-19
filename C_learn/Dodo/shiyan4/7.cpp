#include <iostream>
#include <cmath>
using namespace std;
double squareRoot(double x) {
    if (x < 0)
        throw 1;
    else
        return x * x;
}
int main() {
    double x;
    cin >> x;
    try {
        cout << squareRoot(x);
    } catch (int) {
        cout << "Invalid" << endl;
    }
}