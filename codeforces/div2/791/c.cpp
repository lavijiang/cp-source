//使用树状数组动态维护

#include <bits/stdc++.h>
using namespace std;
int n,q;

vector<int> tr[2];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c,int tag)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[tag][i] += c;
}

int sum(int x,int tag)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[tag][i];
    return res;
}

void solve(){
    cin>>n>>q;
    tr[0] = vector<int>(n+1);
    tr[1] = vector<int>(n+1);
    vector<vector<int>> s(2,vector<int>(1e5+2));
    
    while(q--){
        int t,x1,y1,x2,y2;
        cin>>t;
        if(t==3){
            cin>>x1>>y1>>x2>>y2;
            int re1 = sum(x2,0) - sum(x1-1,0);
            int re2 = sum(y2,1) - sum(y1-1,1);
            if(re1 == (x2-x1+1) || re2 == (y2-y1+1)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cin>>x1>>y1;
            if(t==1){
                if(s[0][x1] == 0){
                    add(x1, 1, 0);
                }
                if(s[1][y1] == 0){
                    add(y1, 1, 1);
                }
                s[0][x1]++;
                s[1][y1]++;
            }else{
                s[0][x1]--;
                s[1][y1]--;
                if(s[0][x1] == 0){
                    add(x1, -1, 0);
                }
                if(s[1][y1] == 0){
                    add(y1, -1, 1);
                }
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}
