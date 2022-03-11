#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;

void solve(){
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>> vp;
    for(int i=1;i<=m;i++){
        ll x,w;
        cin>>x>>w;
        vp.push_back({w,{x,i}});
    }
    sort(vp.begin(),vp.end());
    ll sum = 0;
    vector<pair<ll,ll>> vpd;
    for(int i=0;i<2*n;i++){
        sum += vp[i].first;
        vpd.push_back(vp[i].second);
    }
    sort(vpd.begin(),vpd.end());
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<vpd[i].second<<" "<<vpd[2*n-1-i].second<<endl;
    }
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}