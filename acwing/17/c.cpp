//二分+双指针

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int n,m;
const int N = 1e5+2;
LL a[N],b[N];

bool check(LL r){
    int i = 0;
    for (int j=0; i < n && j < m;){
        if(a[i]>=b[j]-r && a[i]<=b[j]+r){
            i++;
        }else if(a[i]<b[j]-r){
            return false;
        }else{
            j++;
        }
    }
    return i >= n;
}

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; i ++ ) cin>>a[i];
    for (int i = 0; i < m; i ++ ) cin>>b[i];
    
    LL l = 0, r = 2e9+1;
    while(l<r){
        LL mid = l+r >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<l;
    return 0;
}
