#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

void solve(){
    int n;
    cin>>n;
    vector<string> g(n);
    vector<int> tg(n);
    for (int i = 0; i < n; i ++ ) {
        cin>>g[i];
        int nu = 0;
        for (int j = 0; j < n; j ++ ){
            if(g[i][j]=='1'){
                nu++;
            }
        }
        tg[i] = nu;
    }
    int minNum = n*n;
    for (int st = 1; st <= n; st ++ ){
        int tot = 0;
        for (int i = 0; i < n; i ++ ){
            int rt = (st+i)%n;
            tot += tg[i];
            if(g[i][(rt-1+n)%n]=='0'){
                tot ++;
            }else{
                tot --;
            }
        }
        minNum = min(minNum,tot);
    }
    cout<<minNum<<endl;
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
