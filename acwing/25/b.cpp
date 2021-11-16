//注意1和n之间必然存在一条路：若是铁路，则求1到n的公路最短路；反之，则求铁路最短路
#include <bits/stdc++.h>
using namespace std;

const int N = 402;
int g[N][N];
int n,m;
int dist[N];

void getRes(int d){
    queue<int> q;
    q.push(1);
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(i==t) continue;
            if(g[t][i]==d && dist[i]>dist[t]+1){
                dist[i] = dist[t]+1;
                if(i==n) return;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    if(m==n*(n-1)/2){
        cout<<-1<<endl;
        return 0;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a][b] = 1;
        g[b][a] = 1;
    } 
    getRes(1-g[1][n]);
    if(dist[n]==0x3f3f3f3f){
        cout<<-1<<endl;
        return 0;
    }
    if(dist[n]>1){
        cout<<dist[n]<<endl;
        return 0;
    }
    return 0;
}
