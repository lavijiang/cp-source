//dp: 按最后一位是0还是1区分

#include<bits/stdc++.h>
using namespace std;
int t,k;
int l[100002],r[100002];
const int N = 1e9+7;
int f[100010];

int main()
{
    cin>>t>>k;
    int maxd = 1;
    for(int i=0;i<t;i++){
        cin>>l[i]>>r[i];
        maxd = max(maxd,r[i]);
    }
    
    f[0] = 1;
    for(int i =1;i<=maxd;i++){
        if(i<k){
            f[i] = 1;
        }else{
            f[i] = (f[i-1]+f[i-k])%N;
        }
    }
    
    for(int i = 1;i<=maxd;i++) f[i] = (f[i]+f[i-1])%N;
    for(int i=0;i<t;i++){
        cout<<(f[r[i]]-f[l[i]-1]+N)%N<<endl;
    }
    
    return 0;
}