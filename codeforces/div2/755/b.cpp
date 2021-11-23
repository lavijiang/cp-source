//(u+v)(vx+uy) = (x+y)uv
// uvx +vvx+uuy+uvy = xuv+yuv

#include<bits/stdc++.h>

using namespace std;

int t;
int x,y;
int main()
{
    cin>>t;
    while(t--){
        cin>>x>>y;
        int d = x/3;
        int tot = 0;
        tot += d*y;
        x %= 3;
        d = y/3;
        tot += d*x;
        y %= 3;
        if(x==2&&y==2){
            tot += 2;
        }else if(x!=0 && y!=0){
            tot += 1;
        }
        cout<<tot<<endl;
    }
    return 0;
}
