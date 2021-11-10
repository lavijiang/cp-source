//https://www.acwing.com/problem/content/3731/

//最小生成树：Kruskal算法(加边)和Prim算法(加点)
//https://www.acwing.com/blog/content/405/
//prim：当不断加入点的过程中，如果加点（建立边）的代价高于在该点设立发电站的代价，则应该在该点设立发电站
//先假定所有的节点都建了一个发电站

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
const int N = 2002;
int pre[N];//pre代表最小生成树中点的连接关系
bool vis[N];
int x[N],y[N],c[N],k[N],dist[N];
LL g[N][N];//dist代表点到最小生成树的最短距离 g代表点之间距离 
vector<int> fa;
LL res = 0;
void prim(){
    for(int i=1;i<=n;i++){
        dist[i] = c[i];
    }
    for(int i=1;i<=n;i++){
        int t = -1;
        for(int j = 1;j<=n;j++){
            if(!vis[j] && (t==-1 || dist[j]<dist[t])){
                t = j;
            }
        }
        vis[t] = true;
        if(!pre[t]){
            fa.push_back(t);
        }
        res += dist[t];

        for(int j=1;j<=n;j++){
            if(!vis[j] && dist[j]>g[j][t]){
                dist[j] = g[j][t];
                pre[j] = t;
            }
        }
    }
}

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i ++ ){
        cin>>x[i]>>y[i];
    }
    for (int i = 1; i <= n; i ++ ){
        cin>>c[i];
    }
    for (int i = 1; i <= n; i ++ ){
        cin>>k[i];
    }

    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= n; j ++ ){
                LL tmp = LL(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
                g[i][j] = tmp;
                g[j][i] = tmp;
        }
    }
    
    prim();
    cout<<res<<endl;
    cout<<fa.size()<<endl;
    for(int a:fa){
        cout<<a<<" ";
    }
    cout<<endl;
    cout<<n-fa.size()<<endl;
    for(int i=1;i<=n;i++){
        if(pre[i]){
            cout<<i<<" "<<pre[i]<<endl;
        }
    }
    return 0;
}

