#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e3 + 10;
int n, m, tot = 1;
int op[N], sg[N], flag[N];
void init() {
    op[1] = 1;
    tot = 1;
    for (int i = 2;; i++) {
        op[i] = op[i - 1] * 2;
        tot = i;
        if (op[i] > N) break;
    }
}
void get_sg() {
    sg[0] = 0;
    for (int i = 1; i < N; i++) {
        memset(flag, 0, sizeof(flag));
        for (int j = 1; j <= tot && op[j] <= i; j++) flag[sg[i - op[j]]] = 1;
        for (int j = 0; j < N; j++) {
            if (!flag[j]) {
                sg[i] = j;
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    get_sg();
    while (cin >> n) {
        if (sg[n])
            cout << "Kiki" << endl;
        else
            cout << "Cici" << endl;
    }
}