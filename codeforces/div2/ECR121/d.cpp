#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n;

void solve(){
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];

    for(int i = n-1;i>=0;i--){
        for(int j = i+1;j<n;j++){
            b[i] = max(b[i],b[j]-(a[j]-a[i]));
        }
    }

    vector<ll> dp(n);
    dp[0] = (1ll+b[0])*b[0]/2ll;
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1];
        if(a[i]-a[i-1] >= b[i]){
            dp[i] += (1ll+b[i])*b[i]/2ll;
        }else{
            b[i] = b[i-1]+a[i]-a[i-1];
            dp[i] += (b[i]+b[i-1]+1)*(b[i]-b[i-1])/2ll;
        }
    }
    cout<<dp[n-1]<<endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
