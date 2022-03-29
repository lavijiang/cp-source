#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    set<string> st2,st32,st3;
    string s,ns;
    int flag = 0;
    for(int i = 0;i<n;i++){
        cin>>s;
        ns = s;
        reverse(ns.begin(),ns.end());
        if(s == ns){
            flag = 1;
        }
        if(s.size() == 2){
            if(st2.count(ns) || st32.count(ns)){
                flag = 1;
            }
            st2.insert(s);
        }
        if(s.size() == 3){
            if(st2.count(ns.substr(0,2)) || st3.count(ns)){
                flag = 1;
            }
            st32.insert(s.substr(0,2));
            st3.insert(s);
        }
    }
    cout<<(flag?"YES":"NO")<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
