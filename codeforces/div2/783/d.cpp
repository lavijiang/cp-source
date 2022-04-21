//一道非常有意思的树状数组的题目
//树状数组:
//单点修改:O(log(n))
//区间查询:O(log(n))

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n;
const int maxn = 500005,inf=10000000;
int fen[maxn];

int lowbit(int x){
    return x&-x;
}

int query(int x){
    int res = fen[x];
    while(x){
        res = max(res,fen[x]);
        x -= lowbit(x);
    }
    return res;
}

void update(int x,int v){
    while(x<=n){
        fen[x] = max(fen[x],v);
        x += lowbit(x);
    }
}

void solve(){
    cin>>n;
    vector<ll> a(n+1),pre(n+1),ord(n+1);
    vector<pair<ll,int>> p;
    for(int i= 1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
        p.push_back({pre[i],-i}); 
    }
    sort(p.begin(),p.end());
    for (int i = 0; i < n; i ++ ){
        ord[-p[i].second] = i+1;
    }
    vector<int> dp(n+1);
    for (int i=1; i<=n; i++) {
        fen[i]=-inf;
    }
    
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        if(a[i]>0){
            dp[i]++;
        }else if(a[i]<0){
            dp[i]--;
        }
        
        if(pre[i]>0){
            dp[i] = i;
        }else{
            dp[i] = max(dp[i],query(ord[i])+i);
        }
        
        update(ord[i],dp[i]-i);
    }
    cout << dp[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
        solve();

    return 0;
}