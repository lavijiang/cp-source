//a为在该区间内部的数字个数，b为在区间外部的个数
//a+b=n
//a-b>=k(至少可以分为k段，且每一段在区间内部的个数至少要比区间外部的个数多1)
//a>=(n+k+1)/2 向上取整数
//将原来数组排序，利用双指针可以找到最小的区间[x,y]
//在原来的数组上割出区间即可(只要大1，就分割)

#include<bits/stdc++.h>
using namespace std;

int t,n,k;

void solve(){
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i =0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());

    int seq = (n+k+1)/2;
    pair<int,pair<int,int>> inter = {b[n-1]-b[0]+1,{-1,-1}};
    for(int i = 0;i+seq-1<n;i++){
        inter = min(inter,{b[i+seq-1]-b[i],{b[i],b[i+seq-1]}});
    }
    cout<<inter.second.first<<" "<<inter.second.second<<endl;

    int pre = 0;
    int curr = 0;
    int tot = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>=inter.second.first && a[i]<=inter.second.second){
            curr++;
            if(curr>0 && tot+1<k){
                curr = 0;
                cout<<pre+1<<" "<<i+1<<endl;
                pre = i+1;
                tot++;
            }
        }else{
            curr--;
        }
    }
    cout<<pre+1<<" "<<n<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}