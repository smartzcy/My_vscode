#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
#include <math.h>
using namespace std;
int f[102];
int getf(int q) {
    if (f[q] == q) return f[q];
    f[q] = getf(f[q]);
    return f[q];
}
void mer(int q, int w) {
    int x1 = getf(q);
    int x2 = getf(w);
    if (x1 != x2)
        f[x2] = f[x1];
    return;
}
int main() {
    int n, m, k;
    int a[150][150] = {{0}};
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++) {
        int q, w, e;
        cin >> q >> w >> e;
        if (e == -1) {
            a[q][w] = -1;
            a[w][q] = -1;
        } else {
            mer(q, w);
        }
    }
    for (int i = 0; i < k; i++) {
        int q, w;
        cin >> q >> w;
        if (getf(q) == getf(w) && a[q][w] == -1)
            printf("OK but...\n");
        else if (getf(q) == getf(w) && a[q][w] == 0)
            printf("No problem\n");
        else if (getf(q) != getf(w) && a[q][w] == -1)
            printf("No way\n");
        else if (getf(q) != getf(w) && a[q][w] == 0)
            printf("OK\n");
    }
    return 0;
}
