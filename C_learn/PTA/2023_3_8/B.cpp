#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') {
            int j = i;
            while (s[j] == '6' && j < s.length()) {
                cnt++;
                j++;
            }
            if (cnt > 3 && cnt <= 9) {
                cout << 9;
                i = j - 1;
            } else if (cnt > 9) {
                cout << 27;
                i = j - 1;
            } else if (cnt <= 3) {
                for (; i < j; i++) {
                    cout << s[i];
                }
                i = j - 1;
            }
        } else {
            cout << s[i];
            cnt = 0;
        }
    }

    return 0;
}
