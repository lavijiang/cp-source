//维护连通块，并校验每个位置所处的连通块中是否存在需要的号码牌
//使用并查集维护连通块

#include<bits/stdc++.h>
using namespace std;

set<int> st[101];//每个位置父节点的连通块包含的号码牌
int a[101],d[101],f[101];
int n;

int find(int x){
    if(x!=f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x,int y){
    f[find(y)] = find(x);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i] = i;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++){
        if(i-d[i]>=1){
            merge(i-d[i],i);
        }
        if(i+d[i]<=n){
            merge(i+d[i],i);
        }
    }
    
    for(int i=1;i<=n;i++){
        st[find(i)].insert(a[i]);
    }
    
    for(int i=1;i<=n;i++){
        if(!st[find(i)].count(i)){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}