#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        if (str == "and" || str == "not" || str == "that" || str == "the" || str == "you") flag = true;
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
}