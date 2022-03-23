#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, C;
    cin>>n>>C;
    vector<ll> f(C+1); //使用c个金币可以达到的最大化输出 d*h
    for(int i = 0;i<n;i++){
        int c,d,h;
        cin>>c>>d>>h;
        f[c] = max(f[c],1ll*d*h);
    }

    for (int i = 1; i <= C; i++) {
        for (int j = 2 * i; j <= C; j += i) {
            f[j] = max(f[j], f[i] * (j / i));
        }
    }

    for (int i = 1; i <= C; i++) {
        f[i] = max(f[i],f[i-1]);
    }

    int m;
    cin>>m;
    for (int i = 1; i <= m; i++) {
        ll d,h;
        cin>>d>>h;
        int j = upper_bound(f.begin(),f.end(),d*h)-f.begin();
        if(j>C){
            cout<<-1<<" ";
        }else{
            cout<<j<<" ";
        }
    }

    return 0;
}