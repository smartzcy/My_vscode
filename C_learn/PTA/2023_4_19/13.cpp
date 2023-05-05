#include <iostream>
using namespace std;
int qz[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char z[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
bool istrue(char *a) {
    int sum = 0;
    char *start = a;
    int t = 0;
    for (int i = 0; i <= 16; i++) {
        t = (*start) - '0';
        t *= qz[i];
        sum += t;
        start++;
    }
    if ((*start) == z[sum % 11]) {
        return true;
    }
    return false;
}
int main() {
    char inid[100][19];
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        cin >> inid[i];
    }

    int jsum = 0;
    for (int i = 0; i < n; i++) {
        if (!istrue(inid[i])) {
            cout << inid[i] << endl;
            jsum++;
        }
    }
    if (jsum == 0) {
        cout << "All passed\n";
    }
    return 0;
}
