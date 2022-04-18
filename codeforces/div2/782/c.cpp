#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n;

void solve(){
    ll a,b;
    cin>>n>>a>>b;
    vector<ll> nums(n+1);
    vector<ll> dp(n+1); //dp[i] last poit to move in
    for(int i = 1;i<n+1;i++){
        cin>>nums[i];
        dp[0] += b*nums[i];
    }
    ll res = dp[0];
    for(ll i = 1;i<n+1;i++){
        dp[i] = dp[i-1];
        dp[i] -= (nums[i]-nums[i-1])*(b*(n-i)-a);
        res = min(res,dp[i]);
    }
    cout<<res<<"\n";
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
