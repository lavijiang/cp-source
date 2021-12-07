//二分

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n;
LL h;
int a[102];
 
bool check(LL no,vector<LL> d){
    LL tmp = 0;
    tmp+=no;
    if(tmp>=h){
        return true;
    }
    for(LL a:d){
        tmp += min(a,no);
        if(tmp>=h){
            return true;
        }
    }
    return false;
}
 
int main(){
    cin>>t;
    while (t--)
    {
        cin>>n>>h;
        for(int i=0;i<n;i++) cin>>a[i];
        vector<LL> d;
        for(int i=1;i<n;i++){
            d.push_back(a[i]-a[i-1]);
        }
 
        LL l = 0,r = h;
        while(l<r){
            LL mid = l+r>>1;
            if(check(mid,d)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout<<l<<endl;
    }
    
}
