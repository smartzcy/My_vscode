#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10000] = {0};
struct Bag {
    int id;
    int count;
    int sum;
};
bool cmp(const Bag a, const Bag b) {
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.count != b.count)
        return a.count > b.count;
    return a.id < b.id;
}
int main() {
    int N;
    Bag a[10050];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        a[i].count = 0;
        a[i].id = 0;
        a[i].sum = 0;
    }
    for (int i = 1; i <= N; i++) {
        int t, p, q;
        a[i].id = i;
        scanf("%d", &t);
        while (t--) {
            scanf("%d %d", &p, &q);
            a[p].count++;
            a[p].sum += q;
            a[i].sum -= q;
        }
    }
    sort(a + 1, a + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        printf("%d %.2lf\n", a[i].id, (a[i].sum * 1.0) / 100);
    }
}
