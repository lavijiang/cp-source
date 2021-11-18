#include <bits/stdc++.h>
using namespace std;
int n,r1,c1,r2,c2;
int g[52][52];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
typedef pair<int,int> PII;
vector<vector<PII>> node(2);

void bfs(int a,int b,int c){
    g[a][b] = c;
    node[c-2].push_back({a,b});
    for(int i = 0;i<4;i++){
        int nx = a+dx[i];
        int ny = b+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&g[nx][ny] == 0){
            bfs(nx,ny,c);
        }
    }
}

int main()
{
    string s;
    cin>>n;
    cin>>r1>>c1>>r2>>c2;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=n;j++){
            g[i][j] = s[j-1]-'0';
        }
    }

    bfs(r1,c1,2);
    if(g[r2][c2] == 2){
        cout<<0<<endl;
        return 0;
    }
    bfs(r2,c2,3);
    int res = (r2-r1)*(r2-r1)+(c2-c1)*(c2-c1);
    for(auto a:node[0]){
        for(auto b:node[1]){
            int tmp = (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
            res = min(res,tmp);
        }
    }
    cout<<res<<endl;
    return 0;
}
