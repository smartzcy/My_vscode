#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
const int N = 110;
int n, m, smax;
queue<char> q[N];
stack<char> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> smax;
    for (int i = 1; i <= n; i++) {
        char ch;
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            q[i].push(ch);
        }
    }
    int num;
    cin >> num;
    while (num != -1) {
        if (num != 0) {
            if (q[num].size()) {
                if (s.size() == smax) {
                    cout << s.top();
                    s.pop();
                }
                s.push(q[num].front());
                q[num].pop();
            }
        } else {
            if (s.size()) {
                cout << s.top();
                s.pop();
            }
        }
        cin >> num;
    }
    return 0;
}