#include<stdio.h>
void fun0(){
    printf("����1�ź����Ĵ�ӡ�����\n");
}
void fun1(){
    printf("����2�ź����Ĵ�ӡ�����\n");
}
void fun2(){
    printf("����3�ź����Ĵ�ӡ�����\n");
}
int main(){
    void(*ptr[3])(int)={fun0,fun1,fun2};
    int n;
    while (scanf("%d", &n)!=EOF)
    {
        ptr[n-1](1);
    }
}