//dp
//这里所有的有效数组都是这样的两种形式
//0 1 1 2 3 ... i (近似连续递增，最大值为i)   dp1[i]
//0 1 2 ... i-2 i i-2 (最大值为i，空缺了i-1)  dp2[i]

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n;
const int N = 500002;
const int MOD =  998244353;
int add(int a,int b){
    return (a+b)%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int a;
    while (t--)
    {
        res = 0;
        cin>>n;
        vector<int> dp1(n+3);
        vector<int> dp2(n+3);
        for(int i=0;i<n;i++){
            cin>>a;
            dp2[a] = add(dp2[a],dp2[a]);
            dp2[a+2] = add(dp2[a+2],dp2[a+2]);
            if(a>=2)
                dp2[a] = add(dp2[a],dp1[a-2]);
            dp1[a] = add(dp1[a],dp1[a]);
            if(a>=1)
                dp1[a] = add(dp1[a],dp1[a-1]);
            if(a==0){
                dp1[a]= add(dp1[a],1);
            }else if(a==1){
                dp2[a]= add(dp2[a],1);
            }
        }
        for(int i=0;i<=n+2;i++){
            res= add(res,dp2[i]);
            res= add(res,dp1[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
