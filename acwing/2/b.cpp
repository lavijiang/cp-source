//https://www.acwing.com/problem/content/description/3630/

/*
*贪心，其实就是将其他数字往一个数字上累加
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nums[200002];
int main(){
    int n,t,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>nums[i];
        sort(nums,nums+n);
        for(int j = n-2,i=0;j>=0&&i<k;j--,i++){
            nums[n-1] += nums[j];
        }
        cout<<nums[n-1]<<endl;
    }
    return 0;
}


