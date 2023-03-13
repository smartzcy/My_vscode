// #include <iostream>
// #include <algorithm>
// #include <map>
// using namespace std;
// const int N = 1e5;
// int n, m;
// struct people {
//     char sex;
//     string fa;
// };
// map<string, people> node;
// bool check(string a, string b) {
//     int i = 1;
//     for (string A = a; !A.empty(); A = node[A].fa, i++) {
//         int j = 1;
//         for (string B = b; !B.empty(); B = node[B].fa, i++) {
//             if (i >= 5 && j >= 5) return true;
//             if (A == B && (i < 5 || j < 5)) return false;
//         }
//     }
//     return true;
// }
// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         string a, b;
//         cin >> a >> b;
//         if (b.back() == 'r')
//             node[a] = {'f', b.substr(0, b.length() - 7)};
//         else if (b.back() == 'n')
//             node[a] = {'m', b.substr(0, b.length() - 4)};
//         else
//             node[a].sex = b.back();
//     }
//     cin >> m;
//     while (m--) {
//         string a, se1, b, se2;
//         cin >> a >> se1 >> b >> se2;
//         if (node.find(a) == node.end() || node.find(b) == node.end())
//             cout << "NA" << endl;
//         else if (node[a].sex == node[b].sex)
//             cout << "Whatever" << endl;
//         else if (check(a, b))
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
struct people {
    char sex;
    string fa;
};
map<string, people> mp;
bool chk(string a, string b) {
    int i = 1, j = 0;
    for (string A = a; !A.empty(); A = mp[A].fa, i++) {
        j = 1;
        for (string B = b; !B.empty(); B = mp[B].fa, j++) {
            if (i >= 5 && j >= 5)
                return true;
            if (A == B && (i < 5 || j < 5))
                return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (b.back() == 'r') {
            mp[a] = {'f', b.substr(0, b.size() - 7)};
        } else if (b.back() == 'n') {
            mp[a] = {'m', b.substr(0, b.size() - 4)};
        } else {
            mp[a].sex = b.back();
        }
    }
    int m;
    cin >> m;
    string a, se1, b, se2;
    while (m--) {
        cin >> a >> se1 >> b >> se2;
        if (mp.find(a) == mp.end() || mp.find(b) == mp.end())
            puts("NA");
        else if (mp[a].sex == mp[b].sex)
            puts("Whatever");
        else if (chk(a, b))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
