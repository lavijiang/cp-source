//https://leetcode-cn.com/problems/maximum-path-quality-of-a-graph/

//dfs爆搜 注意每个节点是可以多次进入的

class Solution {
public:
    long long res = 0;
    const static int N = 1002,M = 4002;
    int h[N],ne[M],e[M],w[M],idx;
    vector<int> va;
    int vis[N]; //节点的进入次数
    int maxT;
    void add(int a,int b,int c){
        ne[idx] = h[a];
        e[idx] = b;
        w[idx] = c;
        h[a] = idx++;
    }

    void dfs(int u,long long v,int t){
        if(vis[u]==0){
            v += va[u];
        }
        if(u==0){
            if(v>res){
                res = v;
            }
        }
        vis[u]++;
        for(int i = h[u];i>0;i = ne[i]){
            int a = e[i];
            if(t+w[i]<=maxT){
                dfs(a,v,t+w[i]);
                vis[a]--;
            } 
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        res = 0;
        idx = 1;
        memset(h,0,sizeof h);
        va = values;
        maxT = maxTime;
        for(auto edge:edges){
            add(edge[0],edge[1],edge[2]);
            add(edge[1],edge[0],edge[2]);
        }
        dfs(0,0,0);
        return res;
    }
};
