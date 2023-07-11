#include <iostream>
using namespace std;
const int N = 1e6 + 10;
double dp[N];
int main() {
    int a, b;
    double p, q;
    cin >> a >> b >> p >> q;
    p /= 100;
    q /= 100;
    for (int i = b; i <= a; i++)
        dp[i] = max(p * (dp[i - b] + 2) + (1 - p) * (dp[i - b] + 1), q * (dp[i - b + 1] + 1) + (1 - q) * (dp[i - b] + 1));
    printf("%.15f", b == 1 ? max(a * 1.0 / (1 - q), dp[a]) : dp[a]);
}