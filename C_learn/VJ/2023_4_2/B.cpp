#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int num[2] = {0};
        int tot;
        for (auto i : str) {
            if (i == '1')
                num[1]++;
            else
                num[0]++;
        }
        if (num[1] < num[0])
            tot = num[1];
        else
            tot = num[0];
        if (tot % 2)
            cout << "DA" << endl;
        else
            cout << "NET" << endl;
    }
}