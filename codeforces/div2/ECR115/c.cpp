#include<bits/stdc++.h>
using namespace std;

int t,n,m;

void solve(){
    cin>>n;
    vector<int> a(n);
    long long sum = 0;
    map<int,int> mp;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        sum += a[i];
        mp[a[i]]++;
    }
    sum *= 2;
    if(sum % n){
        cout<<0<<endl;
        return;
    }
    sum /= n;
    long long res1 = 0;
    long long res2 = 0;
    for(auto [k,v]:mp){
        if((long long)k*2 == sum){
            res1 = (long long)v*(v-1)/2;
        }else{
            res2 += (long long)v*mp[sum-k];
        }
    }
    cout<<res1+res2/2<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}