#include <bits/stdc++.h>
using namespace std;

int t,n;

void solve(){
    cin>>n;
    int pn = n/10;
    for(int i=0;i<10 && (n%7);i++){
        n = pn*10+i;
    }
    cout<<n<<endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
