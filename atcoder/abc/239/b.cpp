#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    cin>>x;
    if(x>=0){
        cout<<x/10<<endl;
    }else{
        cout<<(x-9)/10<<endl;
    }
    return 0;
}