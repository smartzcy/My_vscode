#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9;
int d[N] , cnt[N] , vis[N];
int n , m , s;
vector<pair<int,int> > adj[N];
bool spfa(){
    memset(cnt , 0 , sizeof cnt);
    for(int i = 1 ; i <= n;i++) d[i] = inf;
    d[1] = 0;
    queue<int> que;
    que.push(1);
    memset(vis,0,sizeof vis);
    vis[1] = 1;
    while(!que.empty()){
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(auto [v , w] : adj[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return true;
                if(!vis[v]){
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1 ; i <= n ;i++) adj[i].clear();
        for(int i = 1 ; i <= m;i++){
            int u , v , w;
            cin >> u >> v >> w;
            if(w >= 0) adj[v].push_back({u,w});
            adj[u].push_back({v , w});
        }
        if(spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}