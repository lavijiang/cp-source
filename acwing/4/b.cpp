//https://www.acwing.com/problem/content/3698/

//递归思想
//当第n-1次扩充后,数组总数量为2^n-1,数组是对称的。另外注意运算符优先级

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int getRes(LL k,int n){
    if(k == 1LL<<n){
        return n+1;
    }
    if(k > 1LL<<n){
        return getRes((1LL<<n+1)-k,n-1);
    }
    return getRes(k,n-1);
}

int main(){
    int n;
    LL k;
    cin>>n>>k;
    cout<<getRes(k,n)<<endl;
    return 0;
}
