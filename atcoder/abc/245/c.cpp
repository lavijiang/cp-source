#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i =0;i<n;i++) cin>>b[i];
    vector<bool> dpa(n),dpb(n);
    dpa[n-1] = dpb[n-1] = true;
    for(int i = n-2;i>=0;i--){
        if(dpa[i+1] && abs(a[i]-a[i+1])<=k){
            dpa[i] = true;
        }else if(dpb[i+1] && abs(a[i]-b[i+1])<=k){
            dpa[i] = true;
        }

        if(dpa[i+1] && abs(b[i]-a[i+1])<=k){
            dpb[i] = true;
        }else if(dpb[i+1] && abs(b[i]-b[i+1])<=k){
            dpb[i] = true;
        }
    }
    cout<<((dpa[0]||dpb[0])?"Yes":"No");
    return 0;
}
