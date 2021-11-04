//https://www.acwing.com/problem/content/3580/

/*
*观察数据，都是正整数，那么取A、B中最大数，必然满足
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    int am = 0,bm = 0;
    cin>>n;
    while(n--){
        cin>>a;
        am = max(am,a);
    }
    cin>>m;
    while(m--){
        cin>>b;
        bm = max(bm,b);
    }
    cout<<am<<" "<<bm;
    
    return 0;
}
