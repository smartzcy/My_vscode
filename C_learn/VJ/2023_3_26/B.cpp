#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
using namespace std;
int num[6] = {16, 23, 4, 8, 15, 42};
int r;
void ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    fflush(stdout);
    cin >> r;
}
int main() {
    ask(1, 2);
    int a, b, c, d, e, f;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] * num[j] == r) {
                a = num[i];
                b = num[j];
                break;
            }
        }
    }
    ask(1, 3);
    bool flag = false;
    for (int i = 0; i < 6; i++) {
        if (num[i] != a && num[i] * a == r) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        int temp = a;
        a = b;
        b = temp;
    }
    c = r / a;
    ask(1, 4);
    d = r / a;
    ask(1, 5);
    e = r / a;
    f = 108 - (a + b + c + d + e);
    cout << "! " << a << " " << b << " ";
    cout << c << " " << d << " ";
    cout << e << " " << f << endl;
}
