#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string str;
    int ans = 0;
    while (cin >> str) {
        ans = max(ans, (int)str.length());
    }
    cout << ans << endl;
}