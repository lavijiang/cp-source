//两个无向图是否同构：如果同构的话，必然存在一种映射关系 即(1,2,…,N)的一种排列
//点的关联关系一致

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,l,r;
    cin>>n>>m;
    vector<vector<bool>> a(n,vector<bool>(n)),b(n,vector<bool>(n));
    for(int i=0;i<m;i++){
        cin>>l>>r;
        a[l-1][r-1] = a[r-1][l-1] = true;
    }

    for(int i=0;i<m;i++){
        cin>>l>>r;
        b[l-1][r-1] = b[r-1][l-1] = true;
    }
    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    do{
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(a[i][j]!=b[p[i]][p[j]]){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        if(ok){
            cout<<"Yes"<<'\n';
            return 0;
        }
    }while(next_permutation(p.begin(),p.end()))
    cout<<"No"<<'\n';
    return 0;
}
