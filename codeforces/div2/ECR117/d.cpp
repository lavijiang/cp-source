//欧几里得算法

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,x;
int t;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>x;
        int flag = 0;
        while(b){
            if(a%b == x%b && x<=a){
                cout<<"YES"<<endl;
                break;
            }
            swap(a,b);
            b = b%a;
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
