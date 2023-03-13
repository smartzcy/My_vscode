#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int num[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n + 2; i++) cin >> num[i];
        sort(num, num + n + 2);
        long long sum = 0;
        for (int i = 0; i < n + 1; i++) sum += num[i];
        int id = -1;
        for (int i = 0; i <= n; i++) {
            if (sum - num[i] == num[n + 1]) {
                id = i;
                break;
            }
        }
        if (id == -1)
            if (sum - num[n] == num[n]) id = n;
        if (id == -1)
            cout << -1 << endl;
        else {
            for (int i = 0; i < n + 1; i++) {
                if (id != i) cout << num[i] << " ";
            }
            cout << endl;
        }
    }
}