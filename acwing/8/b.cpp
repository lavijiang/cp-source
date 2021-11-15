//dp[i] = max(dp[j]) + a[i] if(i-j == a[i]-a[j]) ==> (a[j]-j == a[i]-i = k)
//res[k] += a[i]  k = a[i]-i

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL res;
int a[200010];

int main()
{
    int n;
    cin >> n;
    unordered_map<int,LL> mp;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        int t = a[i]-i;
        mp[t] += a[i];
        res = max(res,mp[t]);
    }
    cout<<res<<endl;

    return 0;
}

