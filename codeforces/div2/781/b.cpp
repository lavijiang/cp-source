#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int t,n;

void solve(){
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> mp;
    int maxn = 1;
    for(int i = 0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>maxn){
            maxn = mp[a[i]];
        }
    }

    int tot = 0;
    int st = maxn;
    while(st<n){
        st <<= 1;
        tot++;
    }
    int res= tot+n-maxn;
    cout<<res<<'\n';
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}