#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int k = 0;
    int num[10000];
    printf("�ӱ�׼�豸�������ݣ�ֱ�������Ƿ���������Ϊֹ\n");
    while (scanf("%d",&n) == 1){
        num[k++] = n;
    }
    sort(num,num + k);
    for(int i = 0 ; i < k;i++){
        printf(" %d",num[i]);
    }
    return 0;
}