#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int num[5] = {-31 , -31 , -31 , -31 , -31};
    int flag = 0;
    int H1 , H2 , m;
    cin >> H1 >> H2 >> m;
    for(int i = 0 ; i < m ; i++){
        int mm , ss , type;
        scanf("%d:%d %d", &mm, &ss, &type);
        if(type == 3){
            int x;
            scanf("%d",&x);
            if(-num[x - 1] + mm * 60 + ss >= 30 && flag ==1){
                num[x - 1] = mm * 60 + ss;
                H1 += (125 + (int)(0.06 * H1)) / 10;
            }
        }else if(type == 1){
            H1 += 800;
            flag = 1;
        }else if(type == 2){
            H1 += H2;
        }
    }
    cout << H1;
}