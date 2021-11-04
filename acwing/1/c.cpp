//https://www.acwing.com/activity/content/problem/content/4142/

/*
*每个数字必然经过一个环回到原点，那么就只需要求该数所在环的长度
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
int nums[N],vis[N],res[N];
int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>nums[i];
            vis[i] = 0;
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> r;
                for(int u = i;!vis[u];u = nums[u]){
                    r.push_back(u);
                    vis[u] = 1;
                }
                for(int a:r){
                    res[a] = r.size();
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
