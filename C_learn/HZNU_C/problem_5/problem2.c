#include<stdio.h>
int main(){
    int year;
    char *str[] = {"��", "ţ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��"};
    while(scanf("%d",&year) != EOF) {
        if(year >= 1900){
            year = year - 1900;
            year = year % 12;
        }else if(year > 0 && year < 1900){
            year = (year - 1900) * -1;
            year = year % 12;
            year = 12 - year;
        }else{
            year = (year - 1900) * -1;
            year = year % 12;
            year = 12 - year;
            year++;
        }
        printf("%s\n",str[year]);
    }
}