#include <bits/stdc++.h>
using namespace std;
int T, len;
char a[55], b[55];
bool check() {
    queue<char> q;
    for (int i = 1; i <= len; i++) {
        if (b[i] == '(')
            q.push(b[i]);
        else if (b[i] == ')') {
            if (q.size())
                q.pop();
            else
                return false;
        }
    }
    if (q.size())
        return false;
    else
        return true;
}
int main() {
    cin >> T;
    while (T--) {
        scanf("%s", a + 1);
        bool flag = false;
        len = strlen(a + 1);
        if (len % 2 || a[1] == a[len]) {
            cout << "NO" << endl;
            continue;
        }
        b[1] = '(';
        b[len] = ')';
        for (int k = 1; k <= 2; k++) {
            for (int i = 2; i < len; i++) {
                if (a[i] == a[1])
                    b[i] = '(';
                else if (a[i] == a[len])
                    b[i] = ')';
                else if (k == 1)
                    b[i] = '(';
                else
                    b[i] = ')';
            }
            flag = check();
            if (flag) break;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}