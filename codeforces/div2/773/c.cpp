#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,x;
void solve(){
    cin>>n>>x;
    vector<LL> a(n);
    map<LL,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    int res = 0;
    for(auto [k,v]:mp){
        if(v!=0){
            LL nk = k*x;
            if(mp[nk]>=v){
                mp[nk] -= v;
            }else{
                res += v-mp[nk];
                mp[nk] = 0;
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
