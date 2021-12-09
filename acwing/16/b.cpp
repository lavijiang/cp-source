#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> pre(n+1);
    for (int i = 1; i <= n; i ++ ){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    if(pre[n]%3!=0){
        cout<<0;
        return 0;
    }
    int tot = pre[n]/3;
    vector<int> t1(n+1),t2(n+2);
    for (int i = 1; i <= n; i ++ ){
        t1[i] = t1[i-1];
        t2[i] = t2[i-1];
        if(pre[i]==tot){
            t1[i]++;
        }
        if(pre[i]==tot*2){
            t2[i]++;
        }
    }
    LL res = 0;
    for (int i = 1; i <= n-2; i ++ ){
        if(t1[i]==t1[i-1]+1){
            res += t2[n-1]-t2[i];
        }
    }
    cout<<res<<"\n";
    return 0;
}
