#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    if (n > 100 || n < 0)
        cout << "Invalid" << endl;
    else if (n < 60)
        cout << "Failed" << endl;
    else
        printf("%.1f\n", 1.0 + (n - 60) / 10.0);
}