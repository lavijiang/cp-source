//https://www.acwing.com/problem/content/3581/

/*
*显然，不用去操作小于中位数的数字，只需要在k次操作中，尽可能的让中位数及大于中位数的数组的最小值尽可能扩大即可
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+2;
int nums[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    
    int res = nums[n/2];
    for(int i=n/2+1;i<n;i++){
        if((nums[i]-nums[i-1])*(i-n/2)<=k){
            k -= (nums[i]-nums[i-1])*(i-n/2);
        }else{
            res = nums[i-1] + k/(i-n/2);
            k = -1;
            break;
        }
    }
    
    if(k>=0){
        cout<<nums[n-1]+k/(n/2+1)<<endl;
    }else{
        cout<<res<<endl;
    }
    return 0;
}
