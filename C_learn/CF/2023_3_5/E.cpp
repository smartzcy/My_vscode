#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    string str;
    cin >> str;
    int k = 1;
    map<char, int> map1;
    string s = "";
    for (int i = 0; i < n; i++) {
        map1[str[i]]++;
        // cout << str[i] << " " << map1[str[i]] << endl;
        if (map1[str[i]] == 5 && k == 1) {
            for (int j = 1; j <= 5; j++) s += str[i];
            k = 2;
            map1.clear();
        } else if (map1[str[i]] == 7 && k == 2) {
            k = 3;
            for (int j = 1; j <= 7; j++) s += str[i];
            map1.clear();
        } else if (map1[str[i]] == 5 && k == 3) {
            for (int j = 1; j <= 5; j++) s += str[i];
            k = 4;
            break;
        }
    }
    if (k != 4)
        cout << "none" << endl;
    else
        cout << s << endl;
}