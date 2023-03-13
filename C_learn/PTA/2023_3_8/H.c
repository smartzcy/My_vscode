#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define len 10000
void substitute(char a[][len], char *q, char *t1, char *r1, int i);
void dele(char a[][len], int i) {
    int j = 0;
    int k = 0;
    int count = 0;
    char temp[] = "  ";
    /*把行首的空格全部删掉*/
    count = strlen(a[i]);
    for (;;) {
        if (a[i][0] == 32)
            for (j = 0; j < count; ++j)
                a[i][j] = a[i][j + 1];
        else
            break;
    }
    /*把相邻单词间的多个空格换成 1 个空格*/
    for (;;) {
        if (strstr(a[i], temp) != NULL) {
            for (j = (strstr(a[i], temp) - a[i]); j < count; ++j)
                a[i][j] = a[i][j + 1];
        } else
            break;
    }
    /*把标点符号前面的空格删掉*/
    j = 0;
    for (; j < count; ++j)
        if (ispunct(a[i][j + 1]) != 0 && a[i][j] == 32) {
            for (k = j; k < count; ++k)
                a[i][k] = a[i][k + 1];
            --j;
        }
    /*把行尾的空格全部删掉*/
    for (;;) {
        count = strlen(a[i]);
        if (a[i][count - 1] == 32)
            a[i][count - 1] = 0;
        else
            break;
    }
    return;
}
/*把原文中所有独立的can you could you 对应地换成 I can、I could—— 这里“独立”是指被空格或标点符号分隔开的单词,把原文中所有独立的 I 和 me 换成 you*/
void replace(char a[][len], int i) {
    char t1[] = "can you";
    char t2[] = "could you";
    char r1[] = "i can";
    char r2[] = "i could";
    char t3[] = "I";
    char t4[] = "me";
    char r3[] = "you";
    char *q = a[i];
    /*can you*/
    substitute(a, a[i], t1, r1, i);
    /*could you*/
    substitute(a, a[i], t2, r2, i);
    /*I*/
    substitute(a, a[i], t3, r3, i);
    /*me*/
    substitute(a, a[i], t4, r3, i);
    /* i变成I*/
    while (strstr(a[i], r1) != NULL) {
        q = strstr(a[i], r1);
        *q = 'I';
    }
    /* i变成I*/
    while (strstr(a[i], r2) != NULL) {
        q = strstr(a[i], r2);
        *q = 'I';
    }
    return;
}
/*把原文中所有大写英文字母变成小写，除了 I；把原文中所有的问号 ? 换成惊叹号 !；*/
void lower(char a[][len], int i) {
    int j = 0;
    /*感叹号替换*/
    for (j = 0; a[i][j] != 0; ++j)
        if (a[i][j] == '?')
            a[i][j] = '!';
    /*变小写*/
    for (j = 0; a[i][j] != 0; ++j)
        if (a[i][j] != 'I')
            a[i][j] = tolower(a[i][j]);
    return;
}
void substitute(char a[][len], char *q, char *t1, char *r1, int i) {
    char temp1[len] = {0};
    char temp2[len] = {0};
    int count = 0;
    int leap = 0;
    leap = strlen(t1);
    for (;;) {
        if (strstr(q, t1) != NULL) {
            q = strstr(q, t1);
            if ((isalnum(*(q - 1)) != 0 && q != a[i]) || isalnum(*(q + leap)) != 0)
                q = q + leap;
            else {
                count = q - a[i];
                strncpy(temp2, a[i], count);
                strcat(temp2, r1);
                strcpy(temp1, q + leap);
                strcat(temp2, temp1);
                strcpy(a[i], temp2);
                memset(temp1, 0, len);
                memset(temp2, 0, len);
            }
        } else
            break;
    }
    return;
}
int main(void) {
    char a[11][len] = {0};
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; ++i)
        gets(a[i]);
    for (i = 0; i < n; ++i) {
        printf("%s\n", a[i]);
        dele(a, i);
        lower(a, i);
        replace(a, i);
        printf("AI: %s\n", a[i]);
    }
    return 0;
}
