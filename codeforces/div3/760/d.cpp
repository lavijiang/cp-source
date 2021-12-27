#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> num(n);
        int res = 0;
        for(int i=0;i<n;i++) cin>>num[i];
        sort(num.begin(),num.end());
        for(int i=0;i<n-2*k;i++) res+= num[i];
        for(int i=n-2*k;i<n-k;i++){
            res += num[i]/num[i+k];
        }
        cout<<res<<'\n';
    }
    return 0;
}