#include<bits/stdc++.h>
using namespace std;

//堆优化的dijskra算法(正权图的最短路)

class Solution {
public:
    vector<long long> dijskra(int src,vector<vector<pair<int,int>>> g,int n){
        vector<long long> res(n,LONG_MAX/3);
        res[src] = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> q;
        q.push({0,src});
        while(!q.empty()){
            auto [w,d] = q.top();
            q.pop();
            if(res[d] < w) continue;

            for(auto [y,wt]:g[d]){
                if(w+wt <= res[y]){
                    res[y] = w+wt;
                    q.push({res[y],y});
                }
            }
        }
        return res;   
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> g(n),rg(n);
        for(auto e:edges){
            g[e[0]].push_back({e[1],e[2]});
            rg[e[1]].push_back({e[0],e[2]});
        }

        auto d1 = dijskra(src1,g,n);
        auto d2 = dijskra(src2,g,n);
        auto d3 = dijskra(dest,rg,n);

        long long tot = LONG_MAX/3;
        for(int i =0;i<n;i++){
            tot = min(tot,d1[i]+d2[i]+d3[i]);
        }
        return (tot>=LONG_MAX/3)?-1:tot;
    }
};