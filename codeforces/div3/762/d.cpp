//最小值最大 数据规模10^5 => 二分
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,m;
vector<vector<int>> g;
bool check(int v){
    int maxi = 0;
    vector<int> c(m);
    for (int i = 0; i < n; i ++ ){
        bool ok = false;
        for (int j = 0; j < m; j ++ ){
            if(g[j][i]>=v){
                ok = true;
                c[j]++;
            }
        }
        if(!ok) return false; //至少有一个朋友的糖果少于v
    }
    for (int i = 0; i < m; i ++ )
        maxi = max(maxi,c[i]);
    if(maxi<2){
        return false; //需要到n家商店购买
    }
    return true;
}
 
void solve(){
    cin>>m>>n;
    g = vector(m,vector<int>(n));
    for (int i = 0; i < m; i ++ ){
        for (int j = 0; j < n; j ++ ){
            cin>>g[i][j];
        }
    }
    int l = 0,r = 1e9;
    while(l<r){
        int mid = l+r+1>>1;
        if(check(mid)){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    cout<<l<<'\n';
}
int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
