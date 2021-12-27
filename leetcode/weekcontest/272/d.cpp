//转化为最长上升子序列问题（时间复杂度使用二分优化）

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int res = 0;
        int n = arr.size();
        for(int i=0;i<=k-1;i++){
            int tot = 0;
            vector<int> q;
            for(int j = i;j<n;j+=k){
                tot++;
                int d = upper_bound(q.begin(),q.end(),arr[j])-q.begin();
                if(d>=q.size()){
                    q.push_back(arr[j]);
                }else{
                    q[d] = arr[j];
                }
            }
            res += tot-q.size();
        }
        return res;
    }
};
