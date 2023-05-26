#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    for (int i = 2; i <= sqrt(2021); i++)
        if (2021 % i == 0) {
            cout << "NO";
            return 0;
        }
    cout << "Yes";
}