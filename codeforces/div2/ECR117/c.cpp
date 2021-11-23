#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k,x;
int t;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>k>>x;
        if(x>=k*k){
            cout<<2*k-1<<endl;
            continue;
        }
        
        LL d = k*(k+1)/2;
        if(x<d){
            LL g = sqrt(2*x);
            if(g*(g+1)<2*x){
                g++;
            }
            cout<<g<<endl;
            continue;
        }
        x = k*k-x;
        LL g = sqrt(2*x);
        if(g*(g+1)>2*x){
            g--;
        }
        cout<<2*k-1-g<<endl;
    }
    return 0;
}
