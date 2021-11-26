#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL dp[26][26];
LL cd[26];

int main()
{
    string s;
    cin>>s;
    for(char c:s){
        for(int i = 0;i<26;i++){
            dp[i][c-'a'] += cd[i];
        }
        cd[c-'a']++;
    }
    
    LL res = 0;
    for(int i=0;i<26;i++){
        res = max(res,cd[i]);
        for(int j=0;j<26;j++){
            res = max(res,dp[i][j]);
        }
    }
    cout<<res<<endl;
    return 0;
}
