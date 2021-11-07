// https://www.acwing.com/activity/content/problem/content/4198/

/*
*注意到数据范围  n=1e5 直接dp是O(n^2) TLE
*dp优化：1、推公式 2、数据结构
*这题使用数据结构优化：树状数组（提高）；以及离散化（基础）
*树状数组可以动态维护区间问题（和、最大值、最小值、异或）
*dp公式 f[a[i]] = max(f[a[j]])+a[i] j<i&&a[j]<a[i]
*f[k]代表以k结尾的最大的上升子序列和
*f[k]可以用树状数组维护起来，维护一个前缀最大值
*但是a太大（10^9），而n(10^5)合适，因此这里使用离散预处理，降低维护的数组个数
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int n;
vector<int> nums,xs;
typedef long long LL;
LL fw[N],res;

int get(int d){
    return lower_bound(xs.begin(),xs.end(),d)-xs.begin()+1;
}

void add(int x,LL c){
    for(;x<=n;x+=x&-x){
        fw[x] = max(fw[x],c);
    }
}

LL query(int x){
    LL res = 0;
    for(;x>0;x-=x&-x){
        res = max(fw[x],res);
    }
    return res;
}

int main(){
    cin>>n;
    nums = vector<int>(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        xs.push_back(nums[i]);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end()); //离散化处理
    
    res = 0;
    for(int i=0;i<n;i++) {
        int d = get(nums[i]);
        LL tmp = query(d-1)+nums[i]; //dp公式 
        add(d,tmp);
        res = max(res,tmp);
    }
    cout<<res<<endl;
    return 0;
}
