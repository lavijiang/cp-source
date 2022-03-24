#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> sufmax(n,vector<int>(m,0));
    vector<vector<int>> premin(n,vector<int>(m,N));
    for(int i = 0;i<n;i++){
        for (int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }

    vector<pair<int,int>> nu;
    for(int i = 0;i<n;i++){
        nu.push_back({a[i][0],i});
    }
    sort(nu.begin(),nu.end());

    for(int i = n-1;i>=0;i--){ //red的最小
        for (int j = 0; j <m; j++){
            premin[i][j] = a[nu[i].second][j];
            if(i<n-1){
                premin[i][j] = min(premin[i][j],premin[i+1][j]);
            }
            if(j>0){
                premin[i][j] = min(premin[i][j],premin[i][j-1]);
            }
        }
    }

    for(int i = n-1;i>=0;i--){ //red的最大
        for (int j = m-1; j >= 0; j--){
            sufmax[i][j] = a[nu[i].second][j];
            if(i<n-1){
                sufmax[i][j] = max(sufmax[i][j],sufmax[i+1][j]);
            }
            if(j<m-1){
                sufmax[i][j] = max(sufmax[i][j],sufmax[i][j+1]);
            }
        }
    }

    vector<int> mnr(m, N), mxl(m, 0);
    bool flag = false;
    int row = 0;
    int col = 0;
    for(int i = 0;i<n-1;i++){//until i row is color blue
        for(int j = 0;j<m;j++){
            mxl[j] = max(mxl[j], a[nu[i].second][j]); //blue的最大
			if (j > 0) mxl[j] = max(mxl[j], mxl[j - 1]);
        }

        for(int j = m-1;j>=0;j--){
            mnr[j] = min(mnr[j], a[nu[i].second][j]);//blue的最小
			if (j < m-1) mnr[j] = min(mnr[j], mnr[j + 1]);
        }

        for(int j = 0;j<m-1;j++){
            if(mxl[j]<premin[i+1][j] && mnr[j+1]>sufmax[i+1][j+1]){
                flag = true;
                row = i;
                col = j;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        cout<<"YES"<<endl;
        string s(n,'R');
        for(int i = 0;i<=row;i++){
            s[nu[i].second] = 'B';
        }
        cout<<s<<" "<<col+1<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}