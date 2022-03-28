#include<bits/stdc++.h>
using namespace std;

int t,n;
void solve(){
    cin>>n;
    vector<int> p(n*2);
    int st = -1;
    int cnt1 = 0;
    for(int i = 0;i<n;i++){
        cin>>p[i];
        if(p[i]==1){
            st = i;
            cnt1++;
        }
    }

    if(st == -1 || cnt1 > 1){
        cout<<"NO"<<endl;
        return;
    }

    for(int i = n;i<2*n;i++){
        p[i] = p[i-n];
    }
    
    for(int i = st+1;i<st+n;i++){
        if(p[i]>p[i-1]+1){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
