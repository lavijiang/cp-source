//典型的背包问题 尾零的数量等价于选出的k个数的质因子分解中的2的幂次之和与5的幂次之和的最小值
//这里把5的幂次当作重量，2的幂次当作价值，按照01背包的做法转移
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
int n,k;
int d[2][202];
LL a;
int f[202][5010]; //f[i][j]当取了i个数，乘积中因子5的个数为j时的2的最大值
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        while(a%2==0){
            a/=2;
            d[0][i]++;
        }
        while(a%5==0){
            a/=5;
            d[1][i]++;
        }
    }
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    int res = 0;
    for(int j = 1;j<=n;j++){
        for(int i=k;i>=1;i--){
            for(int c = j*25;c>=d[1][j];c--){
                f[i][c] = max(f[i][c],f[i-1][c-d[1][j]]+d[0][j]); 
            }
        }
    }
    for(int j = 1;j<5010;j++){
        res = max(res,min(j,f[k][j]));
    }
    cout<<res<<endl;
    return 0;
}
