#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const pair<int , int>& a, const pair<int , int>& b){
    return a.second < b.second;
}
int main(){
    pair<int , int> num[200000];
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i< n ;i++)
        cin >> num[i].first >> num[i].second;
    sort(num , num + n , cmp);
    int ans = 0 , l = 0;
    for(int i = 0 ; i < n ; i++){
        if(num[i].first < l) continue;
        ans++;
        l = num[i].second + m;
    }
    cout << ans << endl;
    return 0;
}