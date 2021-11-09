//https://www.acwing.com/activity/content/problem/content/4233/

//考察点：拓扑排序
//对所有的点进行拓扑排序，如果无法遍历到所有点，则证明有环，无法构成有向无环图
//对未知方向的边，比较两端点的拓扑顺序，由前指向后即可

#include<bits/stdc++.h>
using namespace std;
int t,n,m;

struct edge{
    int x,y,a;
};

void solve(){
    cin>>n>>m;
    vector<edge> vp(m);
    vector<int> r(n+1);
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        cin>>vp[i].a>>vp[i].x>>vp[i].y;
        if(vp[i].a==1){
            r[vp[i].y]++;
            g[vp[i].x].push_back(vp[i].y);
        }
    }

    queue<int> q;
    vector<int> order;//topSortOrder
    for(int i=1;i<=n;i++){
        if(r[i]==0){
            q.push(i);
            order.push_back(i);
        }
    }

    while(q.size()){
        int d = q.front();
        q.pop();

        for(int nu:g[d]){
            r[nu]--;
            if(r[nu]==0){
                order.push_back(nu);
                q.push(nu);
            }
        }
    }

    if(int(order.size())!=n){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    vector<int> index(n+1);
    for(int i=0;i<n;i++){
        index[order[i]] = i;
    }

    for(edge e:vp){
        if(e.a || index[e.x]<index[e.y]){
            cout<<e.x<<" "<<e.y<<endl;
        }else{
            cout<<e.y<<" "<<e.x<<endl;
        }
    }
}

int main(){
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
