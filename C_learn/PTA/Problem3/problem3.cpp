#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n;i++){
        cout << "pow(" << 3 << "," << i << ") = " << pow(3,i) << endl;
    }
}