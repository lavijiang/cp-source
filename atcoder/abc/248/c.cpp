#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int main(){
    ll n,k,m;
    cin>>n>>m>>k;
    vector<vector<ll> > dp(n+1,vector<ll>(k+1));
    dp[0][0] = 1;
    ll res = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int d = j;d<=k;d++){
                dp[i][d] += dp[i-1][d-j];
                dp[i][d] %= mod;
            }
        }
    }
    for(int j = 1;j<=k;j++){
        res += dp[n][j];
        res %= mod;
    }
    cout<<res<<endl;
    return 0;
}
