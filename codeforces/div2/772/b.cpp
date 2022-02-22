#include<bits/stdc++.h>
using namespace std;

int t,n;
typedef long long LL;
LL x,y;

void solve(){
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int tot = 0;
    for(int i = 1;i<n-1;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            if(i+2<n){
                a[i+1] = max(a[i],a[i+2]);
            }else{
                a[i+1] = a[i];
            }
            tot++;
        }
    }
    cout<<tot<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
