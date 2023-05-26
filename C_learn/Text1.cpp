#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int countPrimeFactors(int n) {
    int count = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) {
        count++;
    }
    return count;
}
int main() {
    int m;
    cin >> m;

    vector<int> container;

    while (m--) {
        container.clear();
        for (int i = 0; i < 10; ++i) {
            int n;
            cin >> n;
            container.push_back(n);
        }
        sort(container.begin(), container.end(), [](int a, int b) {
            int countA = countPrimeFactors(a);
            int countB = countPrimeFactors(b);

            if (countA != countB) {
                return countA > countB;
            } else {
                return a > b;
            }
        });
        cout << container.front() << " " << container.back() << endl;
        container.erase(container.begin());
        container.pop_back();
    }

    return 0;
}
