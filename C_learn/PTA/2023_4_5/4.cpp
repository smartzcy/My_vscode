#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100001;
int dang[MAXN];
vector<int> xuan[MAXN];
int N, M;
int now = 1;
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        xuan[i].push_back(0);
    }
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            xuan[i].push_back(x);
        }
    }
    for (int i = 1; i <= M; i++) {
        int x, j;
        cin >> x >> j;
        if (x == 0) {
            now = xuan[now][j];
        } else if (x == 1) {
            dang[j] = now;
            cout << now << endl;
        } else if (x == 2) {
            now = dang[j];
        }
    }
    cout << now;
    return 0;
}
