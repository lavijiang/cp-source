#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

void solve(){
    ll n;
    cin>>n;
    ll tot = 1;
    while((n&1) == 0){
        n>>=1;
        tot *= 2;
    }
    n >>= 1;
    for(ll i = n-tot+1;i<=n;i++){
        cout<<i<<" ";
    }
    for(ll i = n+1;i<=n+tot;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}