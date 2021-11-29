//二分
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;
LL n,m,k;
LL get(LL d){
    LL tmp = 0;
    for(LL b = 1;b<=min(n,d);b++){
        tmp += min(d/b,m);
    }
    return tmp;
}

int main()
{
    cin>>n>>m>>k;
    LL l = 1, r = n*m;
    while(l<r){
        LL mid = (l+r)>>1;
        LL t = get(mid);
        if(t>=k){
            r = mid;
        }else if(t<k){
            l = mid+1;
        }
    }
    cout<<l;
    return 0;
}
