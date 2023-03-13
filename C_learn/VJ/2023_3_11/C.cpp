// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5;
// int n, m;
// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n >> m;
//         string str;
//         cin >> str;
//         bool flag = 1;
//         for (int i = 0; i < str.length() / 2 && flag; i++) {
//             int j = str.length() - i - 1;
//             if (str[i] == '1') {
//                 if (str[j] == '1')
//                     m -= 2;
//                 else if (str[j] == '?') {
//                     str[j] = '1';
//                     m -= 2;
//                 } else
//                     flag = 0;
//             } else if (str[i] == '0') {
//                 if (str[j] == '0')
//                     n -= 2;
//                 else if (str[j] == '?') {
//                     str[j] = '0';
//                     n -= 2;
//                 } else
//                     flag = 0;
//             } else {
//                 if (str[j] == '1') {
//                     str[i] = '1';
//                     m -= 2;
//                 } else if (str[i] == '0') {
//                     str[i] = '0';
//                     n -= 2;
//                 } else
//                     continue;
//             }
//         }
//         if (n < 0 || m < 0) flag = 0;
//         if (flag) {
//             for (int i = 0; i < str.length() / 2; i++) {
//                 int j = str.length() - i - 1;
//                 if (str[i] == '?') {
//                     if (n >= 2) {
//                         str[i] = '0';
//                         str[j] = '0';
//                         n -= 2;
//                     } else if (m >= 2) {
//                         str[i] = '1';
//                         str[j] = '1';
//                         m -= 2;
//                     }
//                 }
//             }
//         }
//         if (str.length() % 2 == 1) {
//             if (str[str.length() / 2] == '0')
//                 n--;
//             else if (str[str.length() / 2] == '1')
//                 m--;
//             else {
//                 if (n) {
//                     str[str.length() / 2] = '0';
//                     n--;
//                 } else if (m) {
//                     str[str.length() / 2] = '1';
//                     m--;
//                 }
//             }
//         }
//         if (n != 0 || m != 0) flag = 0;
//         if (flag)
//             cout << str << endl;
//         else
//             cout << -1 << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    string s;
    int a, b;
    while (T--) {
        cin >> a >> b;
        cin >> s;
        int f = 1;
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            int j = n - i - 1;
            if (s[i] == '1') {
                if (s[j] == '1')
                    b -= 2;
                else if (s[j] == '?') {
                    s[j] = '1';
                    b -= 2;
                } else
                    f = 0;
            } else if (s[i] == '0') {
                if (s[j] == '0')
                    a -= 2;
                else if (s[j] == '?') {
                    s[j] = '0';
                    a -= 2;
                } else
                    f = 0;
            } else {
                if (s[j] == '1') {
                    s[i] = '1';
                    b -= 2;
                } else if (s[j] == '0') {
                    s[i] = '0';
                    a -= 2;
                } else
                    continue;
            }
        }
        if (a < 0 || b < 0) f = 0;
        if (f) {
            for (int i = 0; i < n / 2; i++) {
                int j = n - i - 1;
                if (s[i] == '?') {
                    if (a >= 2) {
                        s[i] = s[j] = '0';
                        a -= 2;
                    } else if (b >= 2) {
                        s[i] = s[j] = '1';
                        b -= 2;
                    }
                }
            }
        }
        if (n & 1) {
            if (s[n / 2] == '0')
                a--;
            else if (s[n / 2] == '1')
                b--;
            else {
                if (a) {
                    s[n / 2] = '0';
                    a--;
                } else if (b) {
                    s[n / 2] = '1';
                    b--;
                }
            }
        }
        if (a != 0 || b != 0) f = 0;
        if (f == 0)
            cout << -1 << endl;
        else
            cout << s << endl;
    }
}
