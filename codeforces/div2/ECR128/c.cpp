//双指针

#include <bits/stdc++.h>
using namespace std;
int n;
 
void solve(){
    string s;
    cin>>s;
    n = s.size();
    //剩余的0的个数a和移除的1的个数的最大值b
    int r = -1, a = 0,b = count(s.begin(),s.end(),'1'),res = min(b,n-b);
    for(int l = 0;l<n;l++){
        //移动右端点
        while(a<b && r<n-1){
            r++;
            if(s[r] == '1'){
                b--;
            }else{
                a++;
            }
        }
        res = min(res,max(a,b));
        //移动左端点
        if(s[l]=='1'){
            b++;
        }else{
            a--;
        }
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}