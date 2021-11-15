//bfs
//思路：将t作为起始节点来考虑，到达各个节点的最短路
//注意在当前节点看导航时，是看是否沿着下一节点走
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+2;
vector<vector<int>> g;
vector<int> p;
int n,m,k;
int dist[N];
int cnt[N];

void bfs(int st){
    memset(dist,0x3f,sizeof dist);
    dist[st] = 0;

    queue<int> q;
    q.push(st);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int a:g[t]){
            if(dist[a]>dist[t]+1){
                dist[a] = dist[t]+1;
                q.push(a);
                cnt[a] = 1;
            }else if(dist[a] == dist[t]+1){
                cnt[a]++;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    g = vector<vector<int>>(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[b].push_back(a);
    }
    cin>>k;
    p = vector<int>(k);
    for(int i=0;i<k;i++){
        cin>>p[i];
    }

    bfs(p[k-1]);

    int minc = 0,maxc = 0;
    for(int i=0;i<k-1;i++){
        if(dist[p[i]]!=dist[p[i+1]]+1){
            minc++,maxc++;
        }else if(cnt[p[i]]>1){
            maxc++;
        }
    }
    cout<<minc<<" "<<maxc<<endl;
    return 0;
}
