//https://www.acwing.com/problem/content/description/3629/

/*
*居然没有想到暴力!
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        bool flag = false;
        for(int x=0;x<=n/3;x++){
            if(flag) break;
            for(int y = 0;y<=n/5;y++){
                int d = n -3*x-5*y;
                if(d>=0&&d%7==0){
                    flag = true;
                    cout<<x<<" "<<y<<" "<<d/7<<endl;
                    break;
                }
            }
        }
        if(!flag) cout<<-1<<endl;
    }

    return 0;
}


