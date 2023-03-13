#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    printf("cost = %.2f", min(n, 50) * 0.53 + max(0, n - 50) * 0.58);
}