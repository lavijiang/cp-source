//hint: 子字符串必然符合："aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"，其中之一

#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;

int main()
{
    cin>>t;
    vector<string> ss{"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
    while(t--){
        cin>>n>>s;
        int flag = -1;
        for(string a:ss){
            for(int i=0;i+a.size()<=s.size();i++){
                if(a==s.substr(i,a.size())){
                    flag = a.size();
                    break;
                }
            }
            if(flag!=-1) break;
        }
        cout<<flag<<endl;
    }
    
    return 0;
}