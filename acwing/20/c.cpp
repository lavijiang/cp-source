//区间dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int f[5002][5002];
int main()
{
    int n,a;
    cin>>n;
    vector<int> co;
    cin>>a;
    co.push_back(a);
    int pre = a;
    for(int i=1;i<n;i++){
        cin>>a;
        if(a!=pre){
            pre =a;
            co.push_back(a);
        }
    }
    
    for(int le = 1;le<co.size();le++){
        for (int i = 0; i+le < co.size(); i ++ ){
            int r = i+le;
            if(co[i]!=co[r]){
                f[i][r] = min(f[i+1][r],f[i][r-1])+1; 
            }else{
                f[i][r] = f[i+1][r-1]+1;
            }
        }
    }
    cout<<f[0][co.size()-1];
    return 0;
}
