//线段树(学习下)https://oi-wiki.org/ds/seg/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010;
const LL INF = 1e18;
struct Node{
    int l,r;
    LL dt,mn; //dt为懒标记 mn为最小值
}tr[4*N];

int w[N];

void pushup(int u){
    tr[u].mn = min(tr[u<<1].mn,tr[u<<1|1].mn);
}

//懒标记
void pushdown(int u){
    auto &root = tr[u];
    auto &l = tr[u<<1];
    auto &r = tr[u<<1|1];
    l.mn += root.dt;
    r.mn += root.dt;
    l.dt += root.dt;
    r.dt += root.dt;
    root.dt = 0;
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,0,w[l]};
        return;
    }
    tr[u] = {l,r};
    int mid = l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void update(int u,int l,int r,int d){
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].dt += d;
        tr[u].mn += d;
        return;
    }
    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;
    if(l<=mid){
        update(u<<1,l,r,d);
    }
    if(mid<r){
        update(u<<1|1,l,r,d);
    }
    pushup(u);
}

LL query(int u,int l,int r){
    if(tr[u].l>=l && tr[u].r<=r){
        return tr[u].mn;
    }
    pushdown(u);
    int mid = tr[u].l+tr[u].r>>1;
    LL res = INF;
    if(l<=mid){
        res = min(res,query(u<<1,l,r));
    }
    if(mid<r){
        res = min(res,query(u<<1|1,l,r));
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d", &w[i]);
    build(1,0,n-1);
    scanf("%d", &m);
    while (m -- ){
        int l, r, d;
        char c;
        scanf("%d %d%c", &l,&r,&c);
        if(c!='\n'){
             scanf("%d", &d);
            if(l<=r){
                update(1,l,r,d);
            }else{
                update(1,l,n-1,d);
                update(1,0,r,d);
            }
        }else{
            if(l<=r){
                cout<<query(1,l,r)<<endl;
            }else{
                cout<<min(query(1,l,n-1),query(1,0,r))<<endl;
            }
        }
    }
    
    return 0;
}
