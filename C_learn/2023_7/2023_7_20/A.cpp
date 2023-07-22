#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, x, pos, a, b;
int A(int n, int m) {
    int res = 1;
    for (int i = m; i >= 1; i--) {
        res *= n; // n × n-1 × n-2 × ... n-m，m就是需要减1的次数
        n--;
    }
}
int main() {
    cin >> n >> x >> pos;
    cout << A(a, x - 1) * A(b, n - x) * A(n - a - b - 1, n - a - b - 1);
}

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// const int INF = 1e9;
// const int N = 2e5 + 10;
// int q, n;
// int a[N], id[N];
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     cin >> q;
//     while (q--) {
//         int l, r, x, y;
//         cin >> l >> r >> x >> y;
//         for (int i = l; i <= r; i++)
//             if (a[i] == x) a[i] = y;
//     }
//     for (int i = 1; i <= n; i++) cout << a[i] << " ";
// }