#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    long long tot = 0,res = 0;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    int minn = nums[0],maxn = minn;
    for(int i = 0;i<n;i++){
        minn = min(minn,nums[i]);
        maxn = max(maxn,nums[i]);
        if(i){
            tot += abs(nums[i]-nums[i-1]);
        }
    }
    if(n==1){
        if(maxn>=x){
            tot = minn-1;
        }else{
            tot = x-1;
        }
        res = tot;
    }else{
        long long tmp = tot + nums[0]-1;
        for(int i = 1;i<n;i++){
            tmp = min(tot - abs(nums[i]-nums[i-1])+(nums[i]+nums[i-1]-2),tmp);
        }
        tmp = min(tmp,tot+nums[n-1]-1);
        res = tmp;
        if(maxn<=x){
            long long re = tmp + x-nums[0];
            re = min(re,tmp + x-nums[n-1]);
            for(int i = 1;i<n;i++){
                re = min(re,tmp- abs(nums[i]-nums[i-1])+(2*x-nums[i]-nums[i-1]));
            }
            res = re;
        }
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
