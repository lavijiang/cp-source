// constructive algorithms 构造题
// n必然出现在数列的最左或者最右端,且只要符合必然存在一种排列满足情况
// 构造方式 翻转数列中除n以外的所有数

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(nums[0]==n){
            reverse(nums.begin()+1,nums.end());
        }else if(nums[n-1]==n){
            reverse(nums.begin(),nums.end()-1);
        }else {
            cout<<-1<<endl;
            continue;
        }
        for(int a:nums){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
