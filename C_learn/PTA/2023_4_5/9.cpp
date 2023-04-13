#include <iostream>
using namespace std;
int main() {
    int n, minn = 1e7, maxx = 0, n1 = 0, n2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (num > maxx) {
            maxx = num;
            n1 = 1;
        } else if (num == maxx)
            n1++;
        if (num < minn) {
            minn = num;
            n2 = 1;
        } else if (num == minn)
            n2++;
    }
    cout << minn << " " << n2 << endl;
    cout << maxx << " " << n1;
}