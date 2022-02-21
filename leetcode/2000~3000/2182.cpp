class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> t(26);
        for(char c:s){
            t[c-'a']++;
        }
        string res;
        for(int i=25;i>=0;i--){
            int k = i-1;
            while(t[i]){
                int tmp = min(t[i],repeatLimit);
                res += string(tmp,'a'+i);
                t[i] -= tmp;

                if(t[i] == 0){
                    break;
                }

                for(;k>=0;k--){
                    if(t[k]>0){
                        break;
                    }
                }
                if(k<0){
                    return res;
                }
                res.push_back('a'+k);
                t[k]--;
            }
        }
        return res;
    }
};
