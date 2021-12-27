//使用并查集来保存数据的转换关系
//从后向前依次转换
#include<bits/stdc++.h>
using namespace std;

int q;
const int N = 5e5+2;
int main(){
    cin>>q;
    vector<int> t(q),x(q),y(q);
    for(int i=0;i<q;i++){
        cin>>t[i]>>x[i];
        if(t[i]==2){
            cin>>y[i];
        }
    }
    
    vector<int> p(N);
    iota(p.begin(),p.end(),0);
    vector<int> res;
    for(int i=q-1;i>=0;i--){
        if(t[i]==1){
            res.push_back(p[x[i]]);
        }else{
            p[x[i]] = p[y[i]];
        }
    }
    reverse(res.begin(),res.end());
    for(int a:res){
        cout<<a<<" ";
    }
    return 0;
}
