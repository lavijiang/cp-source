//不妨设 dp[i] 为满足 [2^(i-1),2^i)的数字个数
//则dp[i]中的奇数是由 [2^(i-2),2^(i-1))中的数字通过操作2得来
//dp[i]中的偶数是由 [2^(i-3),2^(i-2))中的数字通过操作3得来
//当然还需要注意序列A中可以衍生的数字，这些需要排除，并在计算过程中加上非衍生的数字

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> useless;
    sort(a.begin(),a.end());
    for(int nu:a){
        int x = nu;
        bool flag = false;
        while(x){
            if(useless.count(x)){
                flag = true;
                break;
            }
            if(x & 1){
                x >>= 1;
            }else if(x & 2){
                break; //必然无法从2、3操作衍生得到
            }else{
                x >>= 2;
            }
        }
        if(!flag){
            useless.insert(nu);
        }
    }
    vector<int> cnt(30,0);
    for(int nu:a){
        if(useless.count(nu)){
            cnt[__lg(nu)]++; 
        }
    }

    int ans = 0;
    vector<int> dp(p);
    for(int i=0;i<p;i++){
        if(i<30){
            dp[i] = cnt[i];
        }
        if(i>0){
            dp[i] += dp[i-1];
            if(dp[i]>=mod) dp[i] %= mod;
        }
        if(i>1){
            dp[i] += dp[i-2];
            if(dp[i]>=mod) dp[i] %= mod;
        }
        ans += dp[i];
        if(ans >= mod) ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}
