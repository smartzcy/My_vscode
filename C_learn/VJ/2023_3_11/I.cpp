#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
bool check(int x) {
    if (x >= 0 && x <= n - 2)
        return true;
    else
        return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int u, r, d, l, flag = 0;
        cin >> n >> u >> r >> d >> l;
        for (int i = 0; i < 2 && !flag; i++)
            for (int j = 0; j < 2 && !flag; j++)
                for (int k = 0; k < 2 && !flag; k++)
                    for (int nm = 0; nm < 2 && !flag; nm++) {
                        int u1 = u - i - j;
                        int r1 = r - j - k;
                        int d1 = d - k - nm;
                        int l1 = l - nm - i;
                        if (check(u1) && check(r1) && check(d1) && check(l1)) flag = 1;
                    }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}