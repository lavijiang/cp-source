#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int main(){
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    set<pair<int,int> > st;
    for(int i=0;i<8;i++){
        st.insert({x1+dx[i],y1+dy[i]});
    }
    for(int i=0;i<8;i++){
        if(st.count({x2+dx[i],y2+dy[i]})){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}