#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> h(n);
    ll res = 0;;
    vector<ll> tmp(2);
    for(int i = 0;i<n;i++){
        cin>>h[i];
    }
    sort(h.begin(),h.end());
    for(int i = 0;i<n;i++){
        tmp[1] += (h[n-1]-h[i])/2;//偶数
        tmp[0] += (h[n-1]-h[i])&1;//奇数
    }

    if(tmp[1]-tmp[0]>=2){
        ll d = (tmp[1]-tmp[0])*2;
        ll mo = d%3;
        tmp[0] += d/3;
        tmp[1] = tmp[0];
        if(mo == 1){
            tmp[0]++;
        }else if(mo == 2){
            tmp[1]++;
        }
    }

    if(tmp[1]>=tmp[0]){
        res = tmp[1]*2;
    }else{
        res = tmp[0]*2-1;
    }

    tmp[0] = tmp[1] = 0; 
    for(int i = 0;i<n;i++){
        tmp[1] += (h[n-1]+1-h[i])/2;
        tmp[0] += (h[n-1]+1-h[i])&1;
    }
    if(tmp[1]-tmp[0]>=2){
        ll d = (tmp[1]-tmp[0])*2;
        ll mo = d%3;
        tmp[0] += d/3;
        tmp[1] = tmp[0];
        if(mo == 1){
            tmp[0]++;
        }else if(mo == 2){
            tmp[1]++;
        }
    }

    if(tmp[1]>=tmp[0]){
        res = min(tmp[1]*2,res);
    }else{
        res = min(tmp[0]*2-1,res);
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
