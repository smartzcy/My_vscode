#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int main() {
    cin >> n >> m;
    getchar();
    while (n--) {
        getline(cin, s);
        if (s.find("qiandao") != -1 || s.find("easy") != -1)
            continue;
        else
            m--;
        if (m < 0) break;
    }
    if (m < 0)
        cout << s << endl;
    else
        cout << "Wo AK le";
    return 0;
}