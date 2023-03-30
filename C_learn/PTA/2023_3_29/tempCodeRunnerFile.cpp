#include <iostream>
using namespace std;
int main() {
    string s1 = "", s2 = "";
    string a1, a2;
    cin >> a1 >> a2;
    for (int i = 1; i < a1.length(); i++) {
        if (a1[i] % 2 == a1[i - 1] % 2) {
            s1 += max(a1[i], a1[i - 1]);
        }
    }
    for (int i = 1; i < a2.length(); i++) {
        if (a2[i] % 2 == a2[i - 1] % 2) {
            s2 += max(a2[i], a1[i - 1]);
        }
    }
    if (s1 == s2)
        cout << s1;
    else
        cout << s1 << endl
             << s2 << endl;
}