#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<int> p;
    for(int i=2;i<=200;i++){
        int flag = 1;
        for(int j=2;j*j<=i;j++){
            if((i%j)==0){
                flag = 0;
                break;
            }
        }
        if(flag)
            p.insert(i);
    }

    for(int i=a;i<=b;i++){
        int flag = 0;
        for(int j=c;j<=d;j++){
            if(p.count(i+j)){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout<<"Takahashi"<<endl;
            return 0;
        }
    }
    cout<<"Aoki"<<endl;
    return 0;
}