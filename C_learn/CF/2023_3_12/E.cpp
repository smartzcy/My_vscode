#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
long long n, m;
long long a[N << 2], b[N << 2];
struct node {
    long long l, r;
    long long num;
} seg[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<long long> vec;
    for (int i = 1; i <= n; i++) {
        int l, r, num;
        cin >> l >> r >> num;
        seg[i] = {l, r, num};
        vec.push_back(l);
        vec.push_back(r + 1);
    }
    sort(vec.begin(), vec.end());
    long long cnt = vec.erase(unique(vec.begin(), vec.end()), vec.end()) - vec.begin();
    for (long long i = 1; i <= n; i++) {
        long long ql = lower_bound(vec.begin(), vec.end(), seg[i].l) - vec.begin() + 1;
        long long qr = lower_bound(vec.begin(), vec.end(), seg[i].r + 1) - vec.begin() + 1;
        a[ql] ^= seg[i].num;
        a[qr] ^= seg[i].num;
        b[ql]++;
        b[qr]--;
    }
    long long ans = -1;
    for (int i = 1; i <= cnt; i++) {
        a[i] ^= a[i - 1];
        b[i] += b[i - 1];
        if (b[i] >= m) ans = max(ans, a[i]);
    }
    if (ans == -1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}