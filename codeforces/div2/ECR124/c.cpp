#include<bits/stdc++.h>
using namespace std;

int t,n;
typedef long long ll;
void solve(){
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];
    int m11 = 0,m12 = 0,m21 = 0,m22 = 0;
    for(int i = 1;i<n;i++){
        if(abs(a[0]-b[m11])>abs(a[0]-b[i])){
            m11 = i;
        }
        if(abs(a[n-1]-b[m12])>abs(a[n-1]-b[i])){
            m12 = i;
        }
        if(abs(b[0]-a[m21])>abs(b[0]-a[i])){
            m21 = i;
        }
        if(abs(b[n-1]-a[m22])>abs(b[n-1]-a[i])){
            m22 = i;
        }
    }
    ll res = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
    res = min(res,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
    res = min(res,abs(a[0]-b[m11])+abs(a[n-1]-b[m12])+abs(a[m21]-b[0])+abs(a[m22]-b[n-1]));
    res = min(res,abs(a[0]-b[m11])+abs(a[m21]-b[0])+abs(a[n-1]-b[n-1]));
    res = min(res,abs(a[n-1]-b[m12])+abs(a[m22]-b[n-1])+abs(a[0]-b[0]));
    res = min(res,abs(a[0]-b[m11])+abs(a[m22]-b[n-1])+abs(a[n-1]-b[0]));
    res = min(res,abs(a[n-1]-b[m12])+abs(a[m21]-b[0])+abs(a[0]-b[n-1]));
    cout<<res<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}