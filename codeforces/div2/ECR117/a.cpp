#include<bits/stdc++.h>

using namespace std;
int t,x,y;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>x>>y;
        if((x+y)%2){
            cout<<"-1 -1"<<endl;
        }else{
            if(x%2==1){
                x--;
                y++;
            }
            cout<<x/2<<" "<<y/2<<endl;
        }
    }
    return 0;
}
