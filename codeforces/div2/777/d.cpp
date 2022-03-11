//转化为背包问题
//求x转化为beautiful num乘积方案数的个数
//beautiful num 是d的倍数，但不是d*d的倍数
//离散化因子

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll x,d;

bool is_be(ll g){
    return (g%d == 0) && ((g/d)%d != 0);
}

void solve(){
    cin>>x>>d;
    vector<ll> vp;
    for(ll i = 1;i*i<=x;i++){
        if(x%i == 0){
            vp.push_back(i);
            if(x!=i*i){
                vp.push_back(x/i);
            }
        }
    }

    sort(vp.begin(),vp.end());
    int n = vp.size();
    unordered_map<ll,int> mp;
    for(int i  = 0;i<n;i++){
        mp[vp[i]] = i; //离散化因子
    }

    vector<int> f(n);
    f[0] = 1;

    for(int i = 0;i<n;i++){
        if(is_be(vp[i])){ //尾部追加beautiful num
            for(int j = 0;j<n&&(vp[i]*vp[j]<=x);j++){
                if(x/vp[i]%vp[j] == 0){
                    ll v = vp[i]*vp[j];
                    f[mp[v]] = min(f[mp[v]]+f[j],2);
                }
            }
        }
    }
    if(f[n-1]==2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}