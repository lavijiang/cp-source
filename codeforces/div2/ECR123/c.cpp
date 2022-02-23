#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll t,n,x;
const ll N = -5e8; 
void solve(){
    cin>>n>>x;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++ ) cin>>a[i];
    vector<ll> pre(n+1,N);
    pre[0] = 0;
    vector<vector<ll> > dp(n,vector<ll>(n)); 
    ll maxd = pre[0];
    ll st = 0;
    for(ll l = 1;l<=n;l++){
        for (ll i = 0; i+l-1 < n; i ++ ){
            if(l==1){
                dp[i][i+l-1] = a[i];
            }else{
                dp[i][i+l-1] = dp[i][i+l-2]+a[i+l-1];
            }
            pre[l] = max(pre[l],dp[i][i+l-1]);
        }
    }

    vector<ll> suf(n+1);
    suf[n] = pre[n];
    for(ll i =n-1;i>=0;i--){
        suf[i] = max(pre[i],suf[i+1]);
    }
    
    for(ll i = 0;i<=st;i++){
        cout<<(maxd+x*i)<<" ";
    }
    maxd += st*x;
    for (ll i = st+1; i <= n; i ++ ){
        maxd = max(maxd,suf[i] + x*i);
        cout<<maxd<<" ";
    }
    cout<<endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
