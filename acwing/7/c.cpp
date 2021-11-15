//树形DP
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 3e5+2,M = 6e5+2;
LL w[N],res;
int h[N],e[M],ne[M],c[M],idx = 0,n;

void add(int a,int b,int cc){
    idx++;
    c[idx] = cc;
    ne[idx] = h[a];
    h[a] = idx;
    e[idx] = b;
}

LL dfs(int u,int p){
    LL tot[2] = {0,0};
    for(int d = h[u];d>0;d = ne[d]){
        int ed = e[d];
        if(ed == p) {
            continue;
        }
        LL t = dfs(ed,u);
        if(t - c[d]>tot[0]){
            tot[1] = tot[0];
            tot[0] = t-c[d];
        }else if(t - c[d]>tot[1]){
            tot[1] = t-c[d];
        }
    }

    res = max(res,tot[0]+tot[1]+w[u]);
    return tot[0]+ w[u];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    res = 0;
    int a,b,cc;
    for(int i=0;i<n-1;i++){
        cin>>a>>b>>cc;
        add(a,b,cc);
        add(b,a,cc);
    }

    res = max(res,dfs(1,-1));
    cout<<res<<endl;
    return 0;
}
