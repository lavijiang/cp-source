#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    ll maxn = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        maxn = max(maxn,a[i]);
        sum += a[i];
    }
    sum -= maxn;
    if(maxn == 0){
        cout<<0<<endl;
        return;
    }
    if(maxn<=sum+1){
        cout<<1<<endl;
        return;
    }
    cout<<maxn-sum<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}