#include <iostream>
#include <stack>
using namespace std;
int n, m, k;
int main() {
    cin >> n >> m >> k;
    while (k--) {
        int now = 1, flag = 0;
        stack<int> s;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == now) {
                now++;
                while (!s.empty() && s.top() == now && !flag) {
                    s.pop();
                    now++;
                }
            } else {
                s.push(x);
                if (s.size() > m) flag = 1;
            }
        }
        if (s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
