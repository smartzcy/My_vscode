#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct M {
    string a, b;
};
bool cmp(M a, M b) {
    return a.a < b.a;
}
int main() {
    vector<M> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a1, b1;
        char c;
        cin >> a1 >> c >> b1;
        M l = {a1, b1};
        a.push_back(l);
    }
    sort(a.begin(), a.end(), cmp);
    if (a[0].a != "00:00:00")
        cout << "00:00:00 - " << a[0].a << endl;
    for (int i = 0; i < a.size() - 1; i++)
        if (a[i].b != a[i + 1].a)
            cout << a[i].b << " - " << a[i + 1].a << endl;
    if (a[a.size() - 1].b != "23:59:59")
        cout << a[a.size() - 1].b << " - 23:59:59" << endl;
    return 0;
}