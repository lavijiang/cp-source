//(u+v)(vx+uy) = (x+y)uv
// uvx +vvx+uuy+uvy = xuv+yuv

#include<bits/stdc++.h>

using namespace std;

int t,n;
int a[101],b[101];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int flag = 1;
        for(int i = 0;i<n;i++){
            if(a[i]>b[i] || a[i]+1<b[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
