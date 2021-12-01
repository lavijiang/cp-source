//有环必然为-1 拓扑排序检测
//无环，则从入度为0的点开始依次求路径值 与上面可以合并

#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<vector<int>> g;
int val[300010][26];
int d[300010];
int main()
{
    cin>>n>>m>>s;
    g = vector<vector<int>>(n+1);
    int a,b;
    set<pair<int,int>> sp;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(!sp.count({a,b})){
            sp.insert({a,b});
            d[b]++;
            g[a].push_back(b);
        }
    }
    
    queue<int> q;
    int su = 0;
    for(int i =1;i<=n;i++){
        if(!d[i]){
            su++;
            q.push(i);
            val[i][s[i-1]-'a']++;
        }
    }
    
    int res = 1;
    while(q.size()){
        int no = q.front();
        q.pop();
        for(int ne:g[no]){
            for(int i=0;i<26;i++){
                val[ne][i] = max(val[ne][i],val[no][i]+(s[ne-1]-'a'==i));
                res = max(res,val[ne][i]);
            }
            d[ne]--;
            if(!d[ne]){
                q.push(ne);
                su++;
            }
        }
    }
    if(su < n){
        cout<<-1<<endl;
        return 0;
    }
    cout<<res<<endl;
    return 0;
}