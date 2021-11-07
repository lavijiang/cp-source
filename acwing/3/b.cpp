https://www.acwing.com/activity/content/competition/problem_list/49/

/*
*注意到数据范围  1<=ai<=100，直接暴力的复杂度O(1e7)
*/

#include<bits/stdc++.h>
using namespace std;

int nums[100002];
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>nums[i];
        int res = n-1;
        for(int d = 1;d<=100;d++){
            int tmp = 0;
            for(int i=0;i<n;){
                if(nums[i]!=d){
                    i += k;
                    tmp++;
                }else{
                    i++;
                }
            }
            
            res = min(res,tmp);
        }
        cout<<res<<endl;
    }
    return 0;
}