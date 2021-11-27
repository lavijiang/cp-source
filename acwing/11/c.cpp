//1到n的最短路分为三种情况
//1---->n （固定值）
//1--->a->b--->n
//1--->b->a--->n
//取三者最小值的最大值
//d1[i]:1到i的最短路 d2[i]:n到i的最短路
//那么d1[a]+d2[b] < d1[b]+d2[a] ==> d1[a]-d2[a] < d1[b]-d2[b]
//以d1[i]-d2[i]从小到大排序，那么当选定d2中b节点的时候，a节点是处于b节点之前的d1最大值节点（依次计算得出）
// * * a * b * *   d1
// * * a * b * *   d2
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> q;
int n,m,k;

void bfs(int s,vector<int>& d){
    d[s] = 0;
    vector<bool> vis(n+1,false);
    vis[s] = true;
    queue<int> qu;
    qu.push(s);
    while(!qu.empty()){
        int no = qu.front();
        qu.pop();
        for(int a:g[no]){
            if(!vis[a]){
                d[a] = d[no]+1;
                vis[a] = true;
                qu.push(a);
            }
        }
    }
}


int main()
{
    cin>>n>>m>>k;
    int a,b;
    g = vector<vector<int>>(n+1);
    q = vector<int>(k+1);
    for (int i = 1; i <= k; i ++ ) cin>>q[i];
    for (int i = 0; i < m; i ++ ){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> d1(n+1);
    vector<int> d2(n+1);
    bfs(1,d1);
    bfs(n,d2);
    
    sort(q.begin()+1,q.end(),[&](int i,int j){return d1[i]-d2[i]<d1[j]-d2[j];});
    
    int res = 0;
    int pred1 = d1[q[1]];
    for(int i=2;i<=k;i++){
        int tmp = pred1+1+d2[q[i]];
        res = max(res,tmp);
        pred1 = max(pred1,d1[q[i]]);
    }
    res = min(res,d1[n]);
    cout<<res<<endl;
    return 0;
}