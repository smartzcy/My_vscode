#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int a[N];
int main() {
    n = 10;
    int maxx = 0, minn = 1e5;
    int n1, n2;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        if (maxx < a[i]) {
            n1 = i;
            maxx = a[i];
        }
        if (minn > a[i]) {
            minn = a[i];
            n2 = i;
        }
    }
    cout << maxx << " " << n1 << endl;
    cout << minn << " " << n2 << endl;
}