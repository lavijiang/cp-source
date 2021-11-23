#include<bits/stdc++.h>

using namespace std;
int n,k;
vector<int> r,d,g;

int main()
{
    cin>>n>>k;
    r = vector<int>(n);
    g = vector<int>(n);
    d = vector<int>(n);
    for(int i=0;i<n;i++) {
        cin>>r[i];
        g[i] = r[i];
    }
    int a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        a--,b--;
        if(r[a]>r[b]){
            d[a]++;
        }else if(r[a]<r[b]){
            d[b]++;
        }
    }
    sort(r.begin(),r.end());
    for(int i=0;i<n;i++){
        int tmp = lower_bound(r.begin(),r.end(),g[i])-r.begin();
        cout<<tmp-d[i]<<" ";
    }
    return 0;
}
