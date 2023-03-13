#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    cout << n << "divisible by 2 and 3? " << boolalpha << (n % 2 == 0 && n % 3 == 0) << endl;
    cout << n << "divisible by 2 or 3? " << boolalpha << (n % 2 == 0 || n % 3 == 0) << endl;
    cout << n << "divisible by 2 or 3?, but not both? " << (((n % 2 == 0) ^ (n % 3 == 0)) ? "true" : "false") << endl;
}