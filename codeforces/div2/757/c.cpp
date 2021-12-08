//a|b|b|c = a|b|c 因此对所有区间或操作，可以得到数组的或值
//(1+1)^x = C(x,0)+C(x,1)+...+C(x,x)
//(1-1)^x = C(x,0)-C(x,1)+...+C(x,x)*(-1)^x
//2^(x-1) = C(x,1)+C(x,3)+...+C(x,2k+1) (2k+1<=x)
//这里计算每个位对异或和的总贡献，对于每一位来说
//如果都是0，那么贡献为0
//如果有x个1，n-x个0，子序列的异或和为2^(x-1) * 2^(n-x) = 2^(n-1),与1的个数无关

#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,r;
typedef long long LL;
LL x;
const int mod = 1e9+7;
LL ksm(LL a,LL b){
    LL res = 1;
    LL tmp = a;
    while(b){
        if(b&1){
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cin>>t;
    while (t -- ){
        cin>>n>>m;
        LL tot = 0;
        for (int i = 0; i < m; i ++ ){
            cin>>l>>r>>x;
            tot |= x;
        }
        tot = tot*ksm(2,n-1)%mod;
        cout<<tot<<"\n";
    }
    return 0;
}