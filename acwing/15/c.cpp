//记忆化搜索
//栈标记判环
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1002;

int g[N][N];
int f[N][N];
int st[N][N];
bool is_inf;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x,int y){
    int &v = f[x][y];
    if(v!=-1 || is_inf) return v;
    st[x][y] = 1;
    v = 1;
    for (int i = 0; i < 4; i ++ ){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny] == (g[x][y]+1)%4){
            if(st[nx][ny]){
                is_inf = true;
                return v;
            }
            v = max(v,1+dp(nx,ny));
        }
    }
    st[x][y] = 0;
    return v;
}

int main()
{
    cin>>n>>m;
    vector<string> ga(n);
    for (int i = 0; i < n; i ++ ){
        cin>>ga[i];
        for (int j = 0; j < m; j ++ ){
            if(ga[i][j] == 'W'){
                g[i][j] = 1;
            }else if(ga[i][j] == 'E'){
                g[i][j] = 2;
            }else if(ga[i][j] == 'R'){
                g[i][j] = 3;
            }
        }
    }
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 0; i < n; i ++ ){
        for (int j = 0; j < m; j ++ ){
            int t = dp(i, j);
            if (g[i][j]) t -= 4 - g[i][j];
            res = max(res, t / 4);
        }
    }
    if (is_inf) cout<<"infinity";
    else if (!res) cout<<"none";
    else cout<<res;
    return 0;
}
