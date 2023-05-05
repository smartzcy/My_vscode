#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct node {
    char name[9];
    int array[1000];
    int number;
    double average;
} a[101];
bool cmp(const node &a, const node &b) {
    if (a.number == b.number)
        return a.average < b.average;
    else
        return a.number > b.number;
}
int main() {
    int N, i, k, j, lei, s, temp;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s %d", a[i].name, &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &lei);
            a[i].array[j] = lei;
        }
        sort(a[i].array, a[i].array + k);
        int count = 0;
        for (j = 0; j < k; j++) {
            if (a[i].array[j] != a[i].array[j + 1]) {
                count++;
            }
        }
        a[i].number = count;
        a[i].average = 1.0 * k / count;
    }
    sort(a, a + N, cmp);
    if (N == 0) {
        printf("- - -");
    } else if (N == 1) {
        printf("%s - -", a[0].name);
    } else if (N == 2) {
        printf("%s %s -", a[0].name, a[1].name);
    } else {
        for (i = 0; i < 3; i++) {
            if (i != 0)
                printf(" %s", a[i].name);
            else
                printf("%s", a[i].name);
        }
    }
    return 0;
}
