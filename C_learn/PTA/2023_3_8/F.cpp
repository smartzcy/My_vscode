#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        if (str[0] - '0' + str[1] - '0' + str[2] - '0' == str[3] - '0' + str[4] - '0' + str[5] - '0') {
            cout << "You are lucky!" << endl;
        } else
            cout << "Wish you good luck." << endl;
    }
}