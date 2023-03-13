#include <iostream>
using namespace std;
int n , k , f[100010] , di[100010];
void INIT(){
    for(int i = 1 ; i<= n ; i++) f[i] = i;
}
int find(int x){
    if(x != f[x]){
        int t = find(f[x]);
        di[x] += di[f[x]];
        f[x] = t;
    }
    return f[x];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    cin >> n >> k;
    INIT();
    while(k--){
        int d , x , y;
        cin >> d >> x >> y;
        if(x > n || y > n) cnt++;
        else{
            int fx = find(x);
            int fy = find(y);
            if(d == 1){
                if(fx == fy &&(di[x] - di[y]) % 3 != 0) cnt++;
                else if(fx != fy){
                    f[fx] = fy;
                    di[fx] = di[y] - di[x];
                }
            }else{
                if(fx == fy &&(di[x] - di[y] - 1) % 3 != 0) cnt++;
                else if(fx != fy){
                    f[fx] = fy;
                    di[fx] = di[y] - di[x] + 1;
                }
            }
        }
    }
    cout << cnt << endl;
}