#include <iostream>
using namespace std;
const int maxn = 10000000;
bool not_prime[maxn + 5];
int prime[maxn + 5], tot = 0;
void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
}