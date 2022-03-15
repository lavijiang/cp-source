#include<bits/stdc++.h>
using namespace std;

int t,n,k;
void solve(){
    cin>>n>>k;
    if(n==4 && k ==3){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> vp;
    for(int i =0;i<n/2;i++){
        vp.push_back({i,n-1-i});
    }
    if(k>0){
        if(k<n-1){
            vp[0] = {0,n-1-k};
            if(k<n/2){
                vp[k] = {k,n-1};
            }else{
                vp[n-1-k] = {k,n-1};
            }
        }else{
            vp[0] = {0,n-4};
            vp[1] = {1,3};
            vp[3] = {n-2,n-1};
        }
    }
    for(int i =0;i<n/2;i++){
        cout<<vp[i].first<<" "<<vp[i].second<<endl;
    }
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}