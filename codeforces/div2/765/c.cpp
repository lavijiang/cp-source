//dp[i][j] 前i-1段移除j个路牌且保留第i个路牌所需的通行最短时间
//那么 res = min(dp[n][0~k])
#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
int n,k,l;
void solve(){
    cin>>n>>l>>k;
    vector<int> d(n+1),a(n);
    d[n] = l;
    for(int i = 0;i<n;i++) cin>>d[i];
    for(int i = 0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1,N)); 
    dp[0][0]  = 0;
    for(int i = 1;i<=n;i++){
        dp[i][0] = dp[i-1][0] + a[i-1]*(d[i]-d[i-1]);
    }

    for(int i = 0;i <= n;i++){
        for(int j = 0;j<=min(k,i);j++){
            for(int p = i+1;(p<=n) && (j+p-i-1<=k);p++){
                dp[p][j+p-i-1] = min(dp[p][j+p-i-1],dp[i][j]+a[i]*(d[p]-d[i]));
            }
        }
    }

    int res = INT_MAX;
    for(int i =0;i<=k;i++) res = min(res,dp[n][i]);
    cout<<res<<endl;
}

int main(){
    solve();
    return 0;
}