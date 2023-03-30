#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int num[] = {100, 50, 20, 10, 5, 1};
int main() {
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cout << n / num[i] << endl;
        n %= num[i];
    }
}