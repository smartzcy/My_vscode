#include <iostream>
#include <cmath>
using namespace std;
double computeArea(int n, double side);
int main() {
    int n;
    cin >> n;
    double side;
    cin >> side;
    cout << computeArea(n, side) << endl;
    return 0;
}
double computeArea(int n, double side) {
    double pi = 3.14159;
    return (n * side * side) / (4 * tan(pi / n));
}