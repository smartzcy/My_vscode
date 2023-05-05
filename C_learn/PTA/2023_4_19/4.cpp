#include <stdio.h>
using namespace std;
#define max 20010
int heap[max];
int a[max];
int n, m;
int i, j, k;
int key, cnt = 0;
int x, y;
char str[50];
void creat(int x);
int main() {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &key);
        creat(key);
    }
    for (i = 1; i < max; i++) {
        a[heap[i] + 10000] = i;
    }
    while (m--) {
        scanf("%d ", &x);
        x += 10000;
        scanf("%s", str);
        if (str[0] == 'a') {
            scanf("%d", &y);
            y += 10000;
            if (a[x] / 2 == a[y] / 2)
                printf("T\n");
            else
                printf("F\n");
            scanf("%s %s", str, str);
        } else {
            scanf("%s", str);
            if (str[0] == 'a') {
                scanf("%s %s %d", str, str, &y);
                y += 10000;
                if (a[x] / 2 == a[y])
                    printf("T\n");
                else
                    printf("F\n");
            } else {
                scanf("%s", str);
                if (str[0] == 'r') {
                    if (a[x] == 1)
                        printf("T\n");
                    else
                        printf("F\n");
                } else {
                    scanf("%s %d", str, &y);
                    y += 10000;
                    if (a[y] / 2 == a[x])
                        printf("T\n");
                    else
                        printf("F\n");
                }
            }
        }
    }
    return 0;
}
void creat(int x) {
    heap[++cnt] = x;
    int t = cnt;
    while (t > 1 && heap[t] < heap[t / 2]) {
        heap[t] = heap[t / 2];
        heap[t / 2] = x;
        t = t / 2;
    }
    heap[t] = x;
}
