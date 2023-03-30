#include <iostream>
using namespace std;
int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7};
    int *p = a;
    cout << *++p;
    return 0;
}