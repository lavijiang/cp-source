#include<bits/stdc++.h>

using namespace std;
int t,n,x,y;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n>>x>>y;
        if(x>n/2+1 || y<n/2){
            cout<<-1<<endl;
            continue;
        }
        if(x<n/2+1 && y<=n/2){
            cout<<-1<<endl;
            continue;
        }
        if(x==n/2+1 && y!=n/2){
            cout<<-1<<endl;
            continue;
        }
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++){
            nums[i] = i;
        }
        if(x<y) swap(nums[x],nums[y]);
        for(int i=n;i>=1;i--){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
