#include<bits/stdc++.h>

using namespace std;
int t,n;

void solve(){
    cin>>n;
    if(n==4){
        cout<<"1 1 1 1\n";
        return;
    }
    if(n%4 == 0){
        cout<<n/4<<" "<<n/4<<" "<<n/4<<" "<<n/4<<"\n";
        return;
    }
    if(n&1){
        cout<<(n-2)/2<<" "<<n/2<<" 1 1\n";
        return;
    }
    cout<<n/2<<" "<<(n-4)/2<<" 1 1\n";
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}