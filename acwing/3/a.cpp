#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,m,n,r,c,res;
    cin>>t;
    while(t--){
        cin>>n>>m>>r>>c;
        res = r+c-2;
        res = max(res,n-r+m-c);
        res = max(res,r-1+m-c);
        res = max(res,n-r+c-1);
        cout<<res<<endl;
    }
    return 0;
}