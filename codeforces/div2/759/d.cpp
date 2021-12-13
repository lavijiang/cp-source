//判断排列的奇偶性
//每一次交换，排列的奇偶性就会变换一次(3环交换等价于两次两两交换，既不改变排列的奇偶性)
//排列的奇偶性可以通过排列的数个数减去环的个数得到
//另外当排列存在相同的数时，排列的奇偶性可以通过交换两个相等的数字来变换(排列的奇偶性任意)

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n;

void solve(){
    cin>>n;
    int a;
    vector<pair<int,int>> num;
    set<int> st;
    for (int i = 0; i < n; i ++ ){
        cin>>a;
        num.push_back({a,i});
        st.insert(a);
    }
    if(st.size()<n){
        cout << "YES"<<'\n';
        return;
    }
    sort(num.begin(),num.end());
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i ++ ){
        if(num[i].second != i){
            mp[num[i].second] = i;
        }else{
            mp[i] = i;
        }
    }
    vector<int> vis(n);
    int tot = 0;
    for (int i = 0; i < n; i ++ ){
        if(vis[i]) continue;
        for(int j = i;!vis[j];j=mp[j]){
            vis[j] = 1;
        }
        tot++;
    }
    if((n-tot)%2==0){
        cout << "YES"<<'\n';
    }else{
        cout << "NO"<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>t;
    while (t -- ){
        solve();
    }
    return 0;
}
