#include<bits/stdc++.h>

using namespace std;
int t,n;
typedef long long ll;
bool check(int d,vector<int>& num){
    ll le = 0;
    for(int i = 0;i<num.size();i++){
        le += max(0,num[i]-(d-i));
    }
    return d-num.size()>=le;
}

void solve(){
    cin>>n;
    map<int,int> mp;
    int nu;
    for(int i = 0;i<n-1;i++){
        cin>>nu;
        mp[nu]++;
    }
    vector<int> num;
    for(auto [k,v]:mp){
        num.push_back(v);
    }
    num.push_back(1);
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());

    int l = num.size(),r = n;
    while(l<r){
        int mid = l+r >> 1;
        if(check(mid,num)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<l<<"\n";
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}