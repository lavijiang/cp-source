#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    LL n,m;
    string s;
    cin>>n>>s;
    m = s.size();
    vector<LL> r(m+1),c(m+1); //还剩多少步
    vector<bool> rr(m+1),cc(m+1); //是否可以下移和右移
    r[0] = n-1;
    c[0] = n-1;
    for(int i=0;i<m;i++){
        c[i+1] = c[i];
        r[i+1] = r[i];
        rr[i+1] = rr[i];
        cc[i+1] = cc[i];
        if(s[i]=='R'){
            c[i+1] -= 1;
            cc[i+1] = true;
        }else{
            r[i+1] -= 1;
            rr[i+1] = true;
        }
    }
    LL res = 0;
    if(rr[m] && cc[m]){
        res += (c[m]+1)*(r[m]+1);
    }else if(rr[m]){
        res += r[m]+1;
    }else{
        res += c[m]+1;
    }
   
    for(int i=m-1;i>=0;i--){
        res += 1;
        if(rr[i]){
            if(s[i] == 'R')
                res += r[m];
        }
        if(cc[i]){
            if(s[i] == 'D')
                res += c[m];
        }
      
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
