#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
struct Node {
    int address;
    int data;
    int next;
};
int main() {
    int first, n;
    cin >> first >> n;
    int b1[N];
    int b2[N];
    Node a[100000];
    for (int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        a[address].address = address;
        a[address].data = data;
        a[address].next = next;
    }
    int i = first;
    int t1 = 0, t2 = 0;
    while (a[i].next != -1) {
        b1[t1++] = a[i].address;
        b2[t2++] = a[i].data;
        i = a[i].next;
    }
    b1[t1++] = a[i].address;
    b2[t2++] = a[i].data;
    int j = 0, min = 0, max = t1 - 1;
    while (t1--) {
        j++;
        if (j % 2 == 1) {
            if (t1 == 0)
                printf("%05d %d -1\n", b1[max], b2[max]);
            else {
                printf("%05d %d %05d\n", b1[max], b2[max], b1[min]);
                max--;
            }
        } else {
            if (t1 == 0)
                printf("%05d %d -1\n", b1[min], b2[min]);
            else {
                printf("%05d %d %05d\n", b1[min], b2[min], b1[max]);
                min++;
            }
        }
    }
    return 0;
}
