#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),c(n+m+1),b(m+1);
    for(int i =0;i<=n;i++) cin>>a[i];
    for(int i =0;i<=n+m;i++) cin>>c[i];
    for(int i = n+m;i>=n;i--){
        for(int j = min(m,i);j>i-n;j--){
            c[i] -= b[j]*a[i-j];
        }
        b[i-n] = c[i]/a[n];
    }
    for(int i =0;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}
