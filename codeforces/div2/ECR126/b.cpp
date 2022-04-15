#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int getRes(int a){
    for(int i = 0;i<=15;i++){
        if((a>>i)&1){
            return 15-i;
        }
    }
    return 15;
}

void solve(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0<<" ";
        return;
    }
    int mint = 15;
    for(int i = 0;i<15;i++){
        mint = min(mint,i+getRes(i+n));
    }
    cout<<mint<<" ";
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
