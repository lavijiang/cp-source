//hash：常见思路将map的value定为pair，尽可能的多记录信息
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
unordered_map<int,PII> mp; //k为序列和减去序列中某个数的余下和  v为{第几个队列，某个数的下标}
int k,n,w[200002];
set<int> st;

int main(){
    cin>>k;
    
    for(int j = 1;j<=k;j++){
        cin>>n;
        int sum = 0;
        for(int i=1;i<=n;i++){
            cin>>w[i];
            sum+=w[i];
        }
        for(int i=1;i<=n;i++){
            int tot = sum-w[i];
            if(st.count(tot) && mp[tot].first != j){
                cout<<"YES"<<endl;
                cout<<mp[tot].first<<" "<<mp[tot].second<<endl;
                cout<<j<<" "<<i<<endl;
                return 0;
            }
            mp[tot] = {j,i};
            st.insert(tot);
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
