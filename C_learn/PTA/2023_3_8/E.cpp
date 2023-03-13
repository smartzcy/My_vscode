#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    double x, y;
    cin >> x >> y;
    double num = (x / y / y);
    printf("%.1f\n", num);
    if (num > 25)
        cout << "PANG" << endl;
    else
        cout << "Hai Xing" << endl;
}