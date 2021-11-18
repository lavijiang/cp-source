#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int p[200002],a[200002],b;
int main()
{
    vector<vector<int>> nums(3);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        cin>>b;
        nums[b-1].push_back(p[i]);
        if(b!=a[i]){
            nums[a[i]-1].push_back(p[i]);
        }
    }
    
    for(int i=0;i<3;i++) sort(nums[i].begin(),nums[i].end());
    vector<int> idx(3);
    set<int> st;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>c;
        int flag = 0;
        while(idx[c-1]<nums[c-1].size() && !flag){
            if(!st.count(nums[c-1][idx[c-1]])){
                flag = 1;
                st.insert(nums[c-1][idx[c-1]]);
            }
            idx[c-1]++;
        }
        if(flag){
            cout<<nums[c-1][idx[c-1]-1]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }
    
    return 0;
}
