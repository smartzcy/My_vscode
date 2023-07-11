#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 10;
long long n, m, k, ans = 0, sq;
long long a[N], id[N], an[N], b[N];
struct query {
    int ql, qr, Id;
    bool operator<(const query &o) const {
        if (id[ql] == id[o.ql]) {
            return qr < o.qr;
        }
        return id[ql] < id[o.ql];
    }
} A[N];
void add(int x) {
    if (b[x] == 0) ans++;
    b[x]++;
}
void del(int x) {
    b[x]--;
    if (b[x] == 0) ans--;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sq = sqrt(n);
    cin >> m;
    for (int i = 1; i <= n; i++) id[i] = (i - 1) / sq + 1;
    for (int i = 1; i <= m; i++) {
        cin >> A[i].ql >> A[i].qr;
        A[i].Id = i;
    }
    sort(A + 1, A + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++) {
        while (l > A[i].ql) add(a[--l]);
        while (r < A[i].qr) add(a[++r]);
        while (l < A[i].ql) del(a[l++]);
        while (r > A[i].qr) del(a[r--]);
        an[A[i].Id] = ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << an[i] << endl;
    }
}