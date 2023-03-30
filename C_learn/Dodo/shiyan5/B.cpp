#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int num[100][2];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        num[1][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                printf("%4d", 1);
            } else {
                num[j][1] = num[j - 1][0] + num[j][0];
                printf("%4d", num[j][1]);
            }
        }
        for (int j = 1; j <= i; j++) num[j][0] = num[j][1];
        num[i][0] = 1;
        cout << endl;
    }
}