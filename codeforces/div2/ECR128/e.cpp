#include <bits/stdc++.h>
using namespace std;
int n;
 
void solve(){
    cin>>n;
    vector<string> g(2);
    cin>>g[0]>>g[1];
    vector<vector<int>> dp(2,vector<int>(n,2*n));
    int st = n,en = -1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2;j++){
            if(g[j][i]=='*'){
                st = min(st,i);
                en = max(en,i);
            }
        }
    }

    dp[0][st] = g[1][st] == '*'? 1: 0;
    dp[1][st] = g[0][st] == '*'? 1: 0;
    for(int i = st+1;i<=en;i++){
        dp[0][i] = min(dp[0][i],dp[1][i-1]+2);
        dp[0][i] = min(dp[0][i],dp[0][i-1]+1+(g[1][i] == '*'? 1: 0));
        dp[1][i] = min(dp[1][i],dp[0][i-1]+2);
        dp[1][i] = min(dp[1][i],dp[1][i-1]+1+(g[0][i] == '*'? 1: 0));
    }
    cout<<min(dp[0][en],dp[1][en])<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}