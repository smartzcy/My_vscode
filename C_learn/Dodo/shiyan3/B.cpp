#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    cout << num[0] << "->" << num[1] << "->" << num[2] << endl;
}