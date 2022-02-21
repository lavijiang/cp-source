class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        vector<int> p;
        for(int i = 1;i*i<=k;i++){
            if(k%i == 0){
                p.push_back(i);
                if(i*i < k) {
                    p.push_back(k/i);
                }
            }
        }

        unordered_map<int,long long> mp;    
        long long res = 0;
        for(int a:nums){
            res += mp[k/__gcd(a,k)];
            for(int b:p){
                if(a%b == 0){
                    mp[b]++;
                }
            }
        }
        
        return res;
    }
};
