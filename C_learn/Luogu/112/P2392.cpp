#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int s[4], ans = 0;
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0, num; j < s[i]; j++) {
            cin >> num;
            if (sum1 >= sum2)
                sum2 += num;
            else
                sum1 += num;
        }
        ans += max(sum1, sum2);
    }
    cout << ans << endl;
}