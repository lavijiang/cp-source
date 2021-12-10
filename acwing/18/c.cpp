#include <bits/stdc++.h>
using namespace std;
int n,res;
vector<vector<int>> g;
int dfs(int u,int p){
    int d = 1;
    for(int ne:g[u]){
        if(ne==p) continue;
        int t = dfs(ne,u);
        if(t%2==0){
            res++;
        }else{
            d += t;
        }
    }
    return d;
}

int main()
{
    cin>>n;
    int a,b;
    g = vector<vector<int>>(n+1);
    for (int i = 0; i < n-1; i ++ ){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    res = 0;
    if(n%2){
        cout<<-1;
        return 0;
    }
    dfs(1,0);
    cout<<res<<endl;
    return 0;
}
