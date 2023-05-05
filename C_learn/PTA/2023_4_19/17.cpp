#include <bits/stdc++.h>
using namespace std;
int main() {
    string str, str1;
    int i;
    getline(cin, str);
    getline(cin, str1);
    int n1 = str1.length();
    for (i = 0; i < n1; i++) {
        while (str.find(str1[i]) != -1) {
            str.erase(str.find(str1[i]), 1);
        }
    }
    cout << str;
}