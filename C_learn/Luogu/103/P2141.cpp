#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num1[101];
    int num[20005];
    for(int i = 0 ; i < n;i++){
        cin >> num1[i];
        num[num1[i]] = 1;
    }
    int sum = 0;
    for(int i = 0 ; i < n;i++){
        for(int j = i + 1 ; j < n;j++){
            if(num[num1[i] + num1[j]] == 1){
                sum++;
                num[num1[i] + num1[j]] = 0;
            }
        }
    }
    cout << sum;
}