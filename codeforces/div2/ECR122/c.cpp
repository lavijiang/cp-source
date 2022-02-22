#include <bits/stdc++.h>
using namespace std;

int t,n;
typedef long long ll;

ll getUpper(ll d1,ll d2){
    return (d1+d2-1)/d2;
}

void solve(){
    ll hc,dc,hm,dm,k,w,a;
    cin>>hc>>dc>>hm>>dm;
    cin>>k>>w>>a;

    bool flag = false;
    for(ll i = 0;i<=k;i++){
        ll nhc = hc + a*i;
        ll ndc = dc + w*(k-i);
        if(getUpper(hm,ndc)<=getUpper(nhc,dm)){
            flag = true;
            break;
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
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
