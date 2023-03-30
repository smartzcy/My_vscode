#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (min(a, b) * 2 < max(a, b) || (a + b) % 3)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}