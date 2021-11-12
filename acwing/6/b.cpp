//dfs更巧妙，这里直接暴力了

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL l,r;
    cin>>l>>r;
    vector<LL> tot;
    vector<LL> h{4,7};
    vector<LL> nums{0};
    LL st = 1;
    while(nums.back()<r){
        vector<LL> nums1;
        for(LL a:h){
            for(LL b:nums){
                LL tmp = a*st+b;
                nums1.push_back(tmp);
            }
        }
        for(int a:nums1){
            tot.push_back(a);
        }
        nums = num1;
    }
    for(int a:tot){
        cout<<a<<endl;
    }
    return 0;
}
