#include<bits/stdc++.h>
using namespace std;

int t,n;
typedef long long LL;
LL x,y;

void solve(){
    cin>>n;
    LL tot = 0;
    LL a;
    for(int i = 0;i<n;i++){
        cin>>a;
        tot |= a;
    }
    cout<<tot<<endl;
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
