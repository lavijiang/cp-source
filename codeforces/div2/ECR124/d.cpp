#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5+2;
typedef long long ll;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void solve(){
    cin>>n;
    vector<pair<int,int>> vp;
    vector<pair<int,int>> res(n);
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vp.push_back({x,y});
        mp[{x,y}] = i;
    }
    set<pair<int,int>> sp;
    for(int i=0;i<n;i++){
        for(int j = 0;j<4;j++){
            int nx = vp[i].first+dx[j];
            int ny = vp[i].second+dy[j];
            sp.insert({nx,ny});
        }
    }

    queue<vector<int>> qv;
    for(auto [x,y]:sp){
        if(!mp.count({x,y})){
            qv.push({x,y,x,y});
        }
    }

    while(!qv.empty()){
        auto a = qv.front();
        qv.pop();

        for(int j = 0;j<4;j++){
            int x = a[0]+dx[j];
            int y = a[1]+dy[j];
            if(!mp.count({x,y})){
                continue;
            }
            res[mp[{x,y}]] = {a[2],a[3]};
            mp.erase({x,y});
            qv.push({x,y,a[2],a[3]});
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
}

int main(){
    solve();
    return 0;
}