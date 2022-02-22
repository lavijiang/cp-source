#include<bits/stdc++.h>
using namespace std;

int t,n;
typedef long long LL;
LL x,y;

void solve(){
    cin>>n;
    vector<LL> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int> > res;
    for(int i=n-3;i>=0;i--){
        if(a[i+1]>a[i+2]){
            cout<<-1<<endl;
            return;
        }
        if(a[i]>a[i+1]){
            if(a[n-1]<0){
                cout<<-1<<endl;
                return;
            }
            a[i] = a[i+1]-a[n-1];
            res.push_back({i+1,i+2});
        }
    }
    cout<<res.size()<<endl;
    for(auto t:res){
        cout<<t.first<<" "<<t.second<<" "<<n<<endl;
    }
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
