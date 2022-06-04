//单调栈 线段树

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 200010;
int n;
const LL NINF = -1e15;

void pushup(vector<LL>& tr,int u)  // 由子节点的信息，来计算父节点的信息
{
    tr[u] = max(tr[u << 1], tr[u << 1 | 1]);
}

LL query(vector<LL>& tr,int u, int l, int r,int L,int R)
{
    if (l >= L && r <= R) {
        return tr[u];   // 树中节点[l,r]，已经被完全包含
    }

    int mid = l + r >> 1;  
    LL v = NINF;
    if (L <= mid) v = max(v,query(tr,u << 1, l, mid, L, R));
    if (R > mid) v = max(v, query(tr,u << 1 | 1, mid+1, r, L, R));

    return v;
}

void modify(vector<LL>& tr,int u, int l, int r, int x, LL v)
{
    if (l == r) {
        tr[u] = v;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) modify(tr,u << 1, l, mid, x, v);
    else modify(tr,u << 1 | 1, mid+1, r, x, v);
    pushup(tr,u);
}

vector<int> preGreater(vector<LL>& a){
    vector<int> res(n+1,0);
    
    stack<int> s;
    for(int i = n;i>=1;i--){
        while(!s.empty() && a[s.top()]<a[i]){
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

vector<int> nextGreater(vector<LL>& a){
    vector<int> res(n+1,n+1);
    
    stack<int> s;
    for(int i = 1;i<=n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}


void solve(){
    cin>>n;
    
    vector<LL> a(n+1),preSum(n+1),sufSum(n+2),preTree(4*n+4),sufTree(4*n+4);
    for (int i = 1; i <= n; i ++ ) cin>>a[i];
    vector<int> pg = preGreater(a);
    vector<int> ng = nextGreater(a);
    
    for (int i = 1; i <= n; i ++ ){
        preSum[i] = preSum[i-1]+a[i];
        modify(preTree,1,1,n,i,preSum[i]);
    }
    for (int i = n; i >= 1; i -- ){
        sufSum[i] = sufSum[i+1]+a[i];
        modify(sufTree,1,1,n,i,sufSum[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n; i ++ ){
        LL rmax = query(preTree,1, 1,n,i,ng[i]-1)-preSum[i];//右侧
        LL lmax = query(sufTree,1, 1,n,pg[i]+1,i)-sufSum[i];
        if (max(lmax, rmax) > 0) {
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}