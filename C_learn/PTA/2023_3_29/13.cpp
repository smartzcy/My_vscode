#include <iostream>
#include <cmath>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string a = "", b = "";
    for (int i = 1; i < s1.length(); i++) {
        if ((s1[i] - '0') % 2 == (s1[i - 1] - '0') % 2) a += max(s1[i], s1[i - 1]);
    }
    for (int i = 1; i < s2.length(); i++) {
        if ((s2[i] - '0') % 2 == (s2[i - 1] - '0') % 2) b += max(s2[i], s2[i - 1]);
    }
    if (a == b)
        cout << a;
    else
        cout << a << endl
             << b;
}
