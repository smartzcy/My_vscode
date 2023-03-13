#include <iostream>
using namespace std;
const int N = 2e3 + 10;
const int mod = 1e9 + 7;
typedef long long int ll;
struct node {
    int x, y;
    ll h;
    bool death;
} insect[N];
int type[N];
ll dis(ll a, ll b, ll c, ll d) {
    return (a - c) * (a - c) + (b - d) * (b - d);
}
int main() {
    int n;
    int cnt = 0, sum = 0;
    cin >> n;
    while (n--) {
        int flag1 = 0;
        int op = 0;
        ++cnt;
        cin >> op;
        if (op == 1) {
            cin >> insect[cnt].x >> insect[cnt].y >> insect[cnt].h;
            type[cnt] = 1;
        } else {
            type[cnt] = 2;
            long long index = 0, minn = LLONG_MAX;
            long long x1 = 0, y1 = 0, atk = 0, r = 0;
            cin >> x1 >> y1 >> atk >> r;
            for (int i = 1; i <= cnt; i++) {
                ll temp = dis(x1, y1, insect[i].x, insect[i].y);
                if (temp < minn && insect[i].h > 0) {
                    minn = temp;
                    index = i;
                }
            }
            x1 = insect[index].x, y1 = insect[index].y;
            for (int i = 1; i <= cnt; i++) {
                if (insect[i].death == 0 && (dis(x1, y1, insect[i].x, insect[i].y) <= (r * r)) && type[i] == 1) {
                    insect[i].h -= 3LL * atk;
                    if (insect[i].h <= 0) {
                        insect[i].death = 1;
                    } else {
                        insect[cnt].death = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (insect[i].death == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
