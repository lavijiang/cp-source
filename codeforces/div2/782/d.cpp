#include<bits/stdc++.h>
using namespace std;
using ll =long long ;

void solve(){
    ll n;
    cin>>n;
    vector<ll> c(n);
    ll tot = 0;
    for(int i = 0;i<n;i++){
        cin>>c[i];
        tot += c[i];
    }
    int k = tot/n;
    vector<ll> ans(n),b(n);
    int lf=n-k;
    for(int i=lf;i<n;i++)   b[i]=n-1;//假设后k个都为1
    for(int i=n-1;i>=0 && lf<=i;i--)
    {
        int cur=c[i]-(b[i]-i);
        if(cur==i+1)    ans[i]=1;
        else if(cur==1)
        {
            ans[i]=0;
            lf--;
            b[lf]=i-1; //if ans[lf]为1，则b[lf]至少为i-1
        }
    }
    for(auto& e:ans)    cout<<e<<" ";
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _=1;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}
