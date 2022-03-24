#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<int> a(11);
    vector<ll> pre(11);
    vector<ll> presum(11);
    vector<ll> po(11);
    k++;
    for(int i = 0;i<n;i++){
        int g;
        cin>>g;
        a[g] = 1;
    }

    int st = -1;
    for(int i = 0;i<11;i++){
        if(a[i]){
            pre[i] = 1;
        }else{
            pre[i] = pre[i-1]*10ll;
        }
        if(i == 0){
            presum[i] = 9;
            po[i] = 1ll;
        }else{
            presum[i] = pre[i]*9ll + presum[i-1];
            po[i] = po[i-1]*10ll;
        }
        if(presum[i]>=k && st == -1){
            st = i;
        }
    }
    if(st == -1){
        st = 10;
    }
    ll tot = 0;
    for(int i = st;i>=0;i--){
        if(i){
            if(presum[i-1]<=k){
                ll g = (k-presum[i-1] + pre[i]-1ll)/pre[i];
                k -= g*pre[i];
                tot += po[i]*g;
                if(k<=0){
                    break;
                }
            }
        }else{
            tot += k;
        }
    }
    cout<<tot<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
