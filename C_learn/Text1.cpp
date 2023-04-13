#include <iostream>
#include <algorithm>
#include <cstring>
#define len 15
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int n, m;
struct stu {
    int no;
    double math, physics, english;
    char name[100];
} st[100];
void searchna(char *name, int t) {
    int i;
    for (i = 0; i < t; i++) {
        if (strcmp(st[i].name, name) == 0) {
            printf("学号\t姓名\t数学\t物理\t英语\n");
            printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", st[i].no, st[i].name, st[i].math, st[i].physics, st[i].english);
        }
    }
}
int main() {
    for (int i = 0; i < 2; i++) {
        int num;
        char ch[100];
        scanf("%d", &num);
        scanf("%s", ch);
        st[i].no = num;
        strcpy(st[i].name, ch);
    }
    char s[100];
    scanf("%s", s);
    searchna(s, 2);
}