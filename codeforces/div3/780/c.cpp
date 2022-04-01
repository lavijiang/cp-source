#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> nu(26,-1);
    vector<int> dp(n,1);
    nu[s[0]-'a'] = 0;
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1]+1;//不保留
        if(nu[s[i]-'a']!=-1){
            if(nu[s[i]-'a'] == 0){
                dp[i] = min(dp[i],i-1);
            }else{
                dp[i] = min(dp[i],dp[nu[s[i]-'a']-1]+i-1-nu[s[i]-'a']);
            }
        }
        nu[s[i]-'a'] = i;
    }
    cout<<dp[n-1]<<endl;
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
