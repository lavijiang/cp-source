//https://oi-wiki.org/string/kmp/
//计算字符串的真前缀函数 nex[i] 
//res = min(min(nex[1~n-1],nex[n]),n-2)

#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int kmp(){
    int n = s.size();
    vector<int> net(n);
    int maxd = 0;
    for(int i=1;i<n;i++){
        int g = net[i-1];
        while(s[i] != s[g] && g > 0){
            g = net[g-1];
        }
        if(s[i]==s[g]) g++;
        net[i] = g;
        if(i<n-1){
            maxd = max(maxd,net[i]);
        }
    }
    if(!net[n-1]){
        return 0;
    }
    
    for(int i = net[n-1];i > 0;i = net[i-1]){
        if(i<=maxd){
            return i;
        }
    }
    return 0;
}

int main()
{
    cin>>t;
    while (t -- ){
        cin>>s;
        int tmp = kmp();
        if(tmp==0){
            cout<<"not exist"<<endl;
        }else{
            cout<<s.substr(0,tmp)<<endl;
        }
    }
    return 0;
}
