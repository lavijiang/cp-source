//https://www.acwing.com/problem/content/description/3631/

/*
*单源最短路:dijkstra算法(贪心)。
*最短路树,保留最短路树中的任意k条边即可
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5+2,M = 2e5+2;
int n,m,k,idx;
int h[N],ne[M],e[M],id[M],w[M];
LL dist[N];
typedef pair<LL,int> PII; //first为到起点距离，second为终点坐标
bool vis[N];
vector<int> res;

void add(int a,int b,int c,int d){
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    e[idx] = b; 
    id[idx] = d;
    idx++;
}

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; //切换为小根堆
    heap.push({0,1});
    while(heap.size()){
        PII d = heap.top();
        heap.pop();
        
        int v = d.second;
        LL distance = d.first;
        if(vis[v]) continue;
        vis[v] = true;

        for(int u = h[v];u!=-1;u=ne[u]){
            int j = e[u];
            if(dist[j]>dist[v]+w[u]){
                dist[j] = dist[v]+w[u];
                heap.push({dist[j],j});
            }
        }
    }
}

//找边 如果一个点到起点的最短距离=该点到临接点的距离+临接点到起点的距离，则该边属于最短路树
void dfs(int v){
    vis[v] = true;
    for(int u = h[v];u!=-1;u=ne[u]){
        int j = e[u];
        if(dist[j] == dist[v] + w[u] && res.size()<k && !vis[j]){
            res.push_back(id[u]);
            dfs(j);
        }
    }
} 

int main(){
    cin>>n>>m>>k;
    int x,y,w;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++){
        cin>>x>>y>>w;
        add(x,y,w,i),add(y,x,w,i);
    }

    dijkstra();
    memset(vis,false,sizeof vis);
    dfs(1);
    cout<<res.size()<<endl;
    for(int a:res){
        cout<<a<<" ";
    }
    return 0;
}
