//https://atcoder.jp/contests/abc245/editorial/3656
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Shape{
    int w,l,t;
}s[400002];

bool cmp(const struct Shape& a,const struct Shape& b){
    if(a.w != b.w) return a.w>b.w;
    return a.t>b.t;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>s[i].w;
        s[i].t = 0;
    }
    for(int i = 0;i<n;i++){
        cin>>s[i].l;
    }
    for(int i = 0;i<m;i++){
        cin>>s[i+n].w;
        s[i+n].t = 1;
    }
    for(int i = 0;i<m;i++){
        cin>>s[i+n].l;
    }
    sort(s,s+m+n,cmp);

    int cnt = 0;
    multiset<int> mt;
    for(int i =0;i<n+m;i++){
        if(s[i].t == 1){
            mt.insert(s[i].l);
        }else{
            auto d = mt.lower_bound(s[i].l);
            if(d == mt.end()){
                cout<<"No"<<endl;
                return 0;
            }else{
                cnt++;
                if(cnt == n){
                    cout<<"Yes"<<endl;
                    return 0;
                }
                mt.erase(d);
            }
        }
    }
    
    return 0;
}
