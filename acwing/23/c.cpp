//博弈论：打表找规律
#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
    cin>>t;
    while (t -- ){
        cin>>n>>k;
        if(k%3!=0){
            if(n%3==0){
                cout<<"Bob"<<endl;
            }else{
                cout<<"Alice"<<endl;
            }
            continue;
        }
        n %= k+1;
        if(n==k+1 || (n%3==0 && n!=k)){
            cout<<"Bob"<<endl;
        }else{
             cout<<"Alice"<<endl;
        }
    }
    return 0;
}
