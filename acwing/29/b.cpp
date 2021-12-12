#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
int n;
LL l,r;

int main()
{
    cin>>n;
    vector<pair<LL,int>> vp;
    for (int i = 0; i < n; i ++ ){
        cin>>l>>r;
        vp.push_back({l,1});
        vp.push_back({r+1,2});
    }
    sort(vp.begin(),vp.end());
    
    vector<LL> res(n+1);
    int tot = 0; //目前重合边数
    LL no = 0;
    for(int i=0;i<vp.size();i++){
        if(no!=vp[i].first){
            if(tot>0){
                res[tot] += vp[i].first - no;
            }
            no = vp[i].first;
        }
        if(vp[i].second == 1){
            tot++;
        }else{
            tot--;
        }
    }
    for (int i = 1; i <= n; i ++ ){
        cout << res[i]<<" ";
    }
    return 0;
}
