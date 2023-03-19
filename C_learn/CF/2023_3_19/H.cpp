#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l, r, b, k;
int main() {
    cin >> l >> r >> b >> k;
    int t = l / b * b;
    if (t < l)
        t += b;
    cout << k * t << endl;
}