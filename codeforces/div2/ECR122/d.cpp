#include <bits/stdc++.h>
using namespace std;

int t,n,k;
const int N = 1001;
vector<int> d;
void solve(){
    cin>>n>>k;
    vector<int> b(n),c(n);
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    vector<int> dp(k+1,-1);
    dp[0] = 0;
    int maxd = 0;
    for(int i=0;i<n;i++){
        for(int j=k;j>=d[b[i]];j--){
            if(dp[j-d[b[i]]]!=-1)
                dp[j] = max(dp[j],dp[j-d[b[i]]]+c[i]);
            maxd = max(maxd,dp[j]);
        }
    }
    cout<<maxd<<endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    
    d = vector<int>(N, N);
    d[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x <= i; ++x) {
          int j = i + i / x;
          if (j < N) d[j] = min(d[j], d[i] + 1);
        }
    }
    
    while(t--){
        solve();
    }
    
    return 0;
}
