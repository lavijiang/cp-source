#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q,u,b;
    cin>>n>>q;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> a(n,vector<int>(20));

    auto dfs = [&](auto self,int u,int p) -> void{
        a[u][0] = x[u];
        for(int v:adj[u]){
            if(p==v){
                continue;
            }
            self(self,v,u);
            vector<int> pa(40);
            merge(a[u].begin(),a[u].end(),a[v].begin(),a[v].end(),pa.begin(),greater());
            a[u].assign(pa.begin(),pa.begin()+20);
        }
    };

    dfs(dfs,0,-1);

    for(int i=0;i<q;i++){
        int v,k;
        cin>>v>>k;
        v--;
        k--;
        cout<<a[v][k]<<endl;
    }

    return 0;
}