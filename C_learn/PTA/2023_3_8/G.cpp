#include <stdio.h>
int main() {
    int N, s, t, a, i = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d %d", &a, &s, &t);
        if (a == 1) {
            if (s < 130) printf("duo chi yu! ");
            if (s == 130) printf("wan mei! ");
            if (s > 130) printf("ni li hai! ");
            if (t < 27) printf("duo chi rou!\n");
            if (t == 27) printf("wan mei!\n");
            if (t > 27) printf("shao chi rou!\n");
        }
        if (a == 0) {
            if (s < 129) printf("duo chi yu! ");
            if (s == 129) printf("wan mei! ");
            if (s > 129) printf("ni li hai! ");
            if (t < 25) printf("duo chi rou!\n");
            if (t == 25) printf("wan mei!\n");
            if (t > 25) printf("shao chi rou!\n");
        }
    }
    return 0;
}
