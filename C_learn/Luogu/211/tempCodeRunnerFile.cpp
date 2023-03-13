
using namespace std;
const int N = 1e5;
int n, m;
long long num[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> m;
            num[j] = max(num[j], num[j - 1]) + m;
            cout << num[j] << " ";
        }