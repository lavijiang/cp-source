#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin>>n>>s;
    string res = "";
    int a = 0,b = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='C'){
            a += b/2;
            b %= 2;
            res += string(a,'A')+string(b,'B');
            res.push_back(s[i]);
            a = 0;
            b = 0;
        }else if(s[i]=='A'){
            a++;
        }else{
            b++;
        }
    }
    a += b/2;
    b %= 2;
    res += string(a,'A')+string(b,'B');
    cout<<res<<endl;
    return 0;
}
