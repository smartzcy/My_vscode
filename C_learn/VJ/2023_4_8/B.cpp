#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    string str[8];
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        cin >> str[i];
        for (int j = 0; j < 8 && flag; j++) {
            if (str[i][j] == '*') {
                cout << (char)('a' + j) << (8 - i);
                flag = false;
            }
        }
    }
}