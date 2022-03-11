#include<bits/stdc++.h>
using namespace std;

int t,n,m;
vector<string> v;

void solve(){
    cin>>n>>m;
    v = vector<string>(n);
    for(int i = 0;i<n;i++) cin>>v[i];

    if(v[0][0] == '1'){
        cout<<-1<<endl;
        return;
    }

    vector<vector<int>> res;
    for(int i = 0;i<n;i++){
        for(int j = m-1;j>0;j--){
            if(v[i][j] == '1'){
                res.push_back({i,j-1,i,j});
            }
        }
    }

    for(int i = n-1;i>0;i--){
        if(v[i][0] == '1'){
            res.push_back({i-1,0,i,0});
        }
    }

    cout<<res.size()<<endl;
    for(auto a:res){
        cout<<a[0]+1<<" "<<a[1]+1<<" "<<a[2]+1<<" "<<a[3]+1<<endl;
    }
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}