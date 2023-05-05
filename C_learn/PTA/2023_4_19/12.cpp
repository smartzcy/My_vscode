#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string s;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, b[11], c[10];
    cin >> s;
    for (int i = 0; i < 11; i++) {
        if (s[i] == '0')
            a[0] = 1;
        else if (s[i] == '1')
            a[1] = 1;
        else if (s[i] == '2')
            a[2] = 1;
        else if (s[i] == '3')
            a[3] = 1;
        else if (s[i] == '4')
            a[4] = 1;
        else if (s[i] == '5')
            a[5] = 1;
        else if (s[i] == '6')
            a[6] = 1;
        else if (s[i] == '7')
            a[7] = 1;
        else if (s[i] == '8')
            a[8] = 1;
        else if (s[i] == '9')
            a[9] = 1;
    }
    int k = 0, n = 0;
    for (int l = 0; l < 10; l++)
        if (a[l] == 1) n++;
    cout << "int[] arr = new int[]{";
    for (int j = 9; j >= 0; j--) {
        if (a[j] == 1 && k < n - 1) {
            cout << j << ",";
            c[k] = j;
            k++;
        } else if (a[j] == 1) {
            cout << j;
            c[k] = j;
            k++;
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int p = 0; p < s.length(); p++)
        for (int t = 0; t < k; t++) {
            if (s[p] - '0' == c[t] && p < 10)
                cout << t << ",";
            else if (s[p] - '0' == c[t])
                cout << t;
        }
    cout << "};" << endl;
}
