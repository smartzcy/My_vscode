#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string a;
        getline(cin, a);
        int k1, k2;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == ',') {
                k1 = i;
                break;
            }
        }
        k2 = a.length() - 1;
        if (k1 < 3 || a.substr(k1 - 3, 3) != "ong" || a.substr(k2 - 3, 3) != "ong") {
            cout << "Skipped" << endl;
            continue;
        }
        int cnt = 0, k3;
        for (int i = k2; i >= 0; i--) {
            if (a[i] == ' ') {
                cnt++;
                if (cnt == 3) {
                    k3 = i;
                    break;
                }
            }
        }
        for (int i = 0; i <= k3; i++) {
            cout << a[i];
        }
        cout << "qiao ben zhong." << endl;
    }
    return 0;
}
