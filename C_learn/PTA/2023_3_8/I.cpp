#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e4 + 10;
int cc[N];
int n, m;
int sushu(int x) {
    if (x == 1) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int ping(int x) {
    int m = 0;
    while (x) {
        int k = x % 10;
        m += k * k;
        x /= 10;
    }
    return m;
}
int duli(int x) {
    for (int i = n; i <= m; i++)
        if (cc[i] == x) return 0;
    return 1;
}
int xingfu(int x) {
    int p[N];
    int a = x;
    for (int i = 0; cc[a] != 1; i++) {
        p[i] = cc[a];
        a = cc[a];
        for (int j = 0; j < i; j++)
            if (p[j] == p[i]) return 0;
    }
    return 1;
}
int main() {
    int flag = 0, count, x;
    cin >> n >> m;
    for (int i = 1; i <= 10000; i++)
        cc[i] = ping(i);
    for (int i = n; i <= m; i++) {
        if (duli(i) && xingfu(i)) {
            cout << i << " ";
            count = 1;
            x = i;
            while (ping(x) != 1) {
                count++;
                x = ping(x);
            }
            if (sushu(i)) {
                count *= 2;
            }
            cout << count << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "SAD" << endl;
    return 0;
}
