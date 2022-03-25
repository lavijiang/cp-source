//如果出现数字1，则不能有连续的数字出现
#include<bits/stdc++.h>
using namespace std;

int t,n;
const int N = 1e9+1;
void solve(){
    cin>>n;
    set<int> st;
    bool flag = true;
    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        st.insert(a);
        if(st.count(a+1) || st.count(a-1)){
            flag = false;
        }
    }

    if(st.count(1) && !flag){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}