//(u+v)(vx+uy) = (x+y)uv
// uvx +vvx+uuy+uvy = xuv+yuv

#include<bits/stdc++.h>

using namespace std;

int t;
typedef long long LL;
LL x,y;
int main()
{
    cin>>t;
    while(t--){
        cin>>x>>y;
        cout<<-x*x<<" "<<y*y<<endl;
    }
    return 0;
}
