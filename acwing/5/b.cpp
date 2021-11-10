// https://www.acwing.com/problem/content/3730/

//位运算

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,k;
LL a[33];

int main(){
    cin>>t;
    while (t -- ){
        cin>>n>>k;
        set<int> st;
        for(int i=0;i<n;i++) cin>>a[i];
        int flag = 0;
        for(int i=0;i<n;i++){
            int s = 0;
            if(flag) break;
            while(a[i]){
                if(a[i]%k==0){
                    a[i]/=k;
                }else if(a[i]%k==1){
                    if(st.count(s)!=0){
                        flag = 1;
                        cout<<"NO"<<endl;
                        break;
                    }
                    st.insert(s);
                    a[i]/=k;
                }else{
                    flag = 1;
                    cout<<"NO"<<endl;
                    break;
                }
                s++;
            }
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
    }
    
    return 0;
}
