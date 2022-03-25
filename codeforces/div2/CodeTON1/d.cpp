//显然连续k个自然数的和是满足条件的
//a,a+1,...,a+k-1（a>0）
//(2a+k-1)k = 2n  2a+k-1和k的奇偶性显然不同
//那么当n是2的幂次方显然不行
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
void solve(){
    cin>>n;
    n *= 2ll;
    ll p = 1;
    while(n%2 ==0){
        n >>= 1;
        p <<= 1;
    }
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    cout<<min(n,p)<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}