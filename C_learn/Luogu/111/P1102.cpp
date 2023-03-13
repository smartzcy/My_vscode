#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
long long n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<long long, long long> map1;
    cin >> n >> m;
    for (long long i = 1, num; i <= n; i++) {
        cin >> num;
        map1[num]++;
    }
    long long sum = 0;
    for (auto i : map1) {
        if (map1.find(i.first + m) != map1.end()) sum += i.second * map1[i.first + m];
    }
    cout << sum << endl;
}