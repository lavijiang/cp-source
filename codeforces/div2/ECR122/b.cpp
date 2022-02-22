#include <bits/stdc++.h>
using namespace std;

int t,n;

void solve(){
    string s;
    cin>>s;
    n = s.size();
    int ze = 0,on = 0;
    for(char c:s){
        if(c=='1'){
            on++;
        }else{
            ze++;
        }
    }
    if(ze != on){
        cout<<min(ze,on)<<endl;
    }else{
        cout<<on-1<<endl;
    }
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
