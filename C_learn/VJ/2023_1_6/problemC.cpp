#include <iostream>
#include<algorithm>
using namespace std;
long long num[200050] , n , m;
bool check(int x){
    long long ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(num[i] >= x) ans += x;
        else ans += num[i] + (x - num[i]) / 2;
    }
    return ans >= m;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        fill(num + 1 , num + n + 1 , 0);
        for(int i = 0 ; i < m ;i++){
            long long x;
            cin >> x;
            num[x]++;
        }
        sort(num + 1 , num + n + 1);
        long long l = 1 , r = m;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}