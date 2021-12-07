//搜索
//从Lab出发向四个方向寻找点，如果这个点的自由度小于等于2,则改点可以被作为候选点并加入起始点
//另外注意第16个case，输出换行较多，将endl换成\n。https://blog.csdn.net/weixin_43272781/article/details/90726422
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+2;
int t,n,m;
string g[N];
int dx[4] = {-1,0,0,1},dy[4] = {0,-1,1,0};
 
int C(int v,int u){
  return v>=0&&v<n&&u>=0&&u<m&&g[v][u]=='.';
}
 
void dfs(int x,int y){
    for(int k = 0;k<4;k++){
        x+=dx[k];
        y+=dy[k];
        int tot = 0;
        if(x>=0&&x<n&&y>=0&&y<m&&g[x][y] == '.'){
            for(int kd = 0;kd<4;kd++){
                tot += C(x+dx[kd],y+dy[kd]);
            }
            if(tot <= 1){
                g[x][y] = '+';
                dfs(x,y);
            }
        }
        x-=dx[k];
        y-=dy[k];
    }
}
 
 
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m;
        int x,y;
        for(int i = 0;i<n;i++){
            cin>>g[i];
            for(int j=0;j<m;j++){
                if(g[i][j] == 'L'){
                    x = i;
                    y = j;
                }
            }
        }
        
        dfs(x,y);
        for(int i = 0;i<n;i++){
            cout<<g[i]<<'\n';
        }
    }
    return 0;
}
