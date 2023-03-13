#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    n /= 10;
    switch (n) {
    case 10:
        cout << "A";
        break;
    case 9: cout << "A"; break;
    case 8: cout << "B"; break;
    case 7: cout << "C"; break;
    case 6: cout << "D"; break;
    default:
        cout << "E";
        break;
    }
}