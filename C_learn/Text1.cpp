#include <iostream>
using namespace std;
int f(int);
int any_function(int (*pf)(int));
int main() {
    cout << any_function(f) << endl;
    return 0;
}
int f(int i) {
    return i * i + i - 12;
}
int any_function(int (*pf)(int)) {
    int n = 0;
    while (pf(n)) ++n;
    return n;
}