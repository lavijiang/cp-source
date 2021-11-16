//bfs
#include <bits/stdc++.h>
using namespace std;

int n,m,k;
const int N = 2e5+2;
int c[N],vis[N];
vector<vector<int>> g;

int bfs(int s){
    unordered_map<int,int> mp;
    int maxc = 1;
    int tot = 1;
    queue<int> q;
    mp[c[s]] = 1;
    vis[s] = 1;
    q.push(s);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int a:g[t]){
            if(!vis[a]){
                mp[c[a]]++;
                vis[a] = 1;
                q.push(a);
                tot++;
            }
        }
    }
    //c++17新特性 结构化绑定
    for(auto &[k,v]:mp){
        if(v>maxc){
            maxc = v;
        }
    }
    return tot - maxc;
}

int main()
{
    cin>>n>>m>>k;
    g = vector<vector<int>>(n+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            res += bfs(i);
        }
    }
    cout<<res<<endl;
    return 0;
}

//并查集 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

int n, m, k;
int p[N], col[N], cnt[N];
vector<int> S[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    for (int i = 1; i <= n; i ++ ) scanf("%d", &col[i]);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        p[find(a)] = find(b);
    }

    for (int i = 1; i <= n; i ++ ) S[find(i)].push_back(i);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        if (S[i].size())
        {
            int t = 0;
            for (auto x: S[i]) t = max(t, ++ cnt[col[x]]);
            res += S[i].size() - t;
            for (auto x: S[i]) -- cnt[col[x]];  //回退
        }

    printf("%d\n", res);
    return 0;
}
