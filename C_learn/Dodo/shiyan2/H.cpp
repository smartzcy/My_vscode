#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    char str[10];
    cin >> str;
    for (int i = 0; i < 4; i++) {
        str[i] = ((str[i] - '0' + 9) % 10 + '0');
    }
    cout << str[2] << str[3] << str[0] << str[1];
}