#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int ans[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            cout << "? " << mid << " " << i << endl;
            char ch;
            cin >> ch;
            if (ch == '=') {
                ans[mid] = i;
                break;
            } else if (ch == '<') {
                l = mid + 1;
            } else
                r = mid - 1;
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}