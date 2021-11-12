//https://www.acwing.com/activity/content/problem/content/4290/

//状态压缩DP
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1<<22;
int f[N]; //代表到达完全图的这个状态，要操作的最小次数
int e[23]; //代表点连接的其他点 例如 e[1] = 1011 则代表 1连接了1、2、4号节点
typedef pair<int, int> PII;
PII res[N]; //first代表前一个状态，second代表是连接的边

int main(){
    cin>>n>>m;
    if(m==n*(n-1)/2){
        cout<<0<<endl;
        return 0;
    }
    
    for(int i=0;i<n;i++){
        e[i] = 1<<i;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        e[a] |= 1<<b;
        e[b] |= 1<<a;
    }
    
    memset(f,0x3f,sizeof f);
    for(int i=0;i<n;i++){
        f[e[i]] = 1; //注意图中无环和重边
        res[e[i]].first = 0;
        res[e[i]].second = i;
    }
    
    for(int i = 0;i < 1<<n;i++){
        if(f[i]==0x3f3f3f3f) continue;
        for(int j = 0;j<n;j++){
            if(i >> j & 1){
                if(f[i|e[j]]>1+f[i]){
                    f[i|e[j]] = 1+f[i];
                    res[i|e[j]].first = i;
                    res[i|e[j]].second = j;
                }
            }
        }
    }
    
    cout<<f[(1<<n)-1]<<endl;
    int tmp = (1<<n)-1;
    while(tmp){
        cout<<res[tmp].second + 1<<" ";
        tmp = res[tmp].first;
    }
    
    return 0;
}
