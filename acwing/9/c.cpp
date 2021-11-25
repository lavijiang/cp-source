//上升 前面只能是上升
//下降 前面可以是下降或者上升 
//两次单调栈 分别计算前半部分升序前缀和和后半部分降序的后缀和
#include<bits/stdc++.h>

using namespace std;
int n;
typedef long long LL;
const int N = 500010;

LL pre[N],suf[N];
LL a[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<pair<int,int>> st;
    st.push({0,0}); //下标和值
    for(int i=1;i<=n;i++){
        while(st.top().second>a[i]){
            st.pop();
        }
        auto g = st.top();
        pre[i] = pre[g.first]+a[i]*(i-g.first);
        st.push({i,a[i]});
    }
    
    st = stack<pair<int,int>>();
    st.push({n+1,0});
    for(int i=n;i>=1;i--){
        while(st.top().second>a[i]){
            st.pop();
        }
        auto g = st.top();
        suf[i] = suf[g.first]+a[i]*(g.first-i);
        st.push({i,a[i]});
    }
    
    LL su = 0, index = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if(suf[i]+pre[i]-a[i]>su){
            su = suf[i]+pre[i]-a[i];
            index = i;
        }
    }
    
    for(int i=index;i<n;i++){
        a[i+1] = min(a[i+1],a[i]);
    }
    for(int i=index;i>1;i--){
        a[i-1] = min(a[i-1],a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
