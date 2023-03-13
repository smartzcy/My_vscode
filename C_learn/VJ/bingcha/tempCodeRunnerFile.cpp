#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , fa[200000];
void INIT(){
    for(int i = 1 ; i <= m ; i++){
        fa[i] = i;
    }
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
}
array<int , 3> edge[100000];
int num , ans;
void kru(){
    sort(edge + 1 , edge + 1 + n);
    INIT();
    ans = 0;
    num = 0;
    for(int i = 1 ; i <= n ; i++){
        // auto [w , u , v] = edge[i];
        int w = edge[i][0];
        int u = edge[i][1];
        int v = edge[i][2];
        int fu = find(u);
        int fv = find(v);
        if(fu != fv){
            num++;
            ans += w;
            fa[fu] = fv;
        }
    }
}
int main(){
    while(cin >> n >> m , n != 0){
        for(int i = 1 , u , v , w ; i <= n ;i++){
            cin >> u >> v >> w;
            edge[i] = {w , u ,v};
        }
        kru();
        int cnt = 0;
        if(num != n - 1)cout << "?" << endl;
        else cout << ans << endl;
    }
}