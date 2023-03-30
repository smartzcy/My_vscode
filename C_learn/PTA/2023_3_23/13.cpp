// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int INF = 1e9;
// const long long mod = 1e9 + 7;
// const int N = 1e5 + 10;
// int n, m;
// long long c[105][105];
// void INIT() {
//     for (int i = 0; i < 105; i++) {
//         c[i][0] = c[i][i] = 1;
//         for (int j = 1; j < i; j++) {
//             c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
//             c[i][j] %= mod;
//         }
//     }
// }
// long long Cof(long long n, long long m) {
//     if (n < m) swap(n, m);
//     return c[n][m];
// }
// long long possible(vector<int> vec) {
//     if (vec.size() == 1 || vec.size() == 0) return 1;
//     vector<int> left, right;
//     for (int i = 1; i < vec.size(); i++) {
//         if (vec[i] > vec[0])
//             right.push_back(vec[i]);
//         else
//             left.push_back(vec[i]);
//     }
//     return (possible(left) % mod) * (possible(right) % mod) * (Cof(left.size(), right.size() + left.size()) % mod);
// }
// int main() {
//     cin >> n;
//     if (n == 0) {
//         cout << 0 << endl;
//         return 0;
//     }
//     INIT();
//     vector<int> vec;
//     for (int i = 0, num; i < n; i++) {
//         cin >> num;
//         vec.push_back(num);
//     }
//     cout << possible(vec) % mod << endl;
// }

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
long C[105][105];
void init() {
    for (int i = 0; i < 105; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
}
long Cof(long n, long m) {
    if (n < m) swap(n, m);
    return C[n][m];
}
long possibility(vector<int> tree) {
    if (tree.size() == 1 || tree.size() == 0) return 1;
    vector<int> left, right;
    for (int i = 1; i < tree.size(); i++)
        if (tree[i] > tree[0])
            right.push_back(tree[i]);
        else
            left.push_back(tree[i]);
    return possibility(left) % MOD * possibility(right) % MOD * Cof(left.size(), left.size() + right.size()) % MOD;
}
int main() {
    int size;
    cin >> size;
    if (size == 0) {
        cout << 0;
        return 0;
    }
    vector<int> tree;
    init();
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        tree.push_back(temp);
    }
    cout << possibility(tree) % MOD;
    return 0;
}
