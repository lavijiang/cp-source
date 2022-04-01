#include<bits/stdc++.h>
using namespace std;

int t,n;
void solve(){
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int st = 0;
    if(n&1){
        if(a[0]+a[1]!=0){
            cout<<-a[2]<<" "<<-a[2]<<" "<<a[0]+a[1]<<" ";
        }else if(a[0]+a[2]!=0){
            cout<<-a[1]<<" "<<a[0]+a[2]<<" "<<-a[1]<<" ";
        }else{
            cout<<a[1]+a[2]<<" "<<-a[0]<<" "<<-a[0]<<" ";
        }
        st = 3;
    }
    for(;st<n;st+=2){
        cout<<-a[st+1]<<" "<<a[st]<<" ";
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
