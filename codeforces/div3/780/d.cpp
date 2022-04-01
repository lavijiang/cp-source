#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+2);
    vector<int> b(n+2);
    vector<int> two(n+2);
    vector<int> zero;
    zero.push_back(0);
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        b[i] = b[i-1];
        two[i] = two[i-1];
        if(a[i]<0){
            b[i]++;
        }
        if(a[i]==2 || a[i] == -2){
            two[i]++;
        }
        if(a[i] == 0){
            zero.push_back(i);
        }
    }
    zero.push_back(n+1);
    b[n+1] = b[n];
    two[n+1] = two[n];
    int maxi = 0;
    pair<int,int> res{1,0};
    for(int i = 0;i<zero.size()-1;i++){
        int st = zero[i];
        int en = zero[i+1];
        if((b[en]-b[st])%2==0){
            int twoNum = two[en] - two[st];
            if(twoNum > maxi){
                maxi = twoNum;
                res = {st+1,en-1};
            }
        }else{
            for(int j = st;j<en;j++){
                if(a[j]<0){
                    int twoNum = two[en] - two[j];
                    if(twoNum > maxi){
                        maxi = twoNum;
                        res = {j+1,en-1};
                    }
                    break;
                }
            }
            for(int j = en;j>st;j--){
                if(a[j]<0){
                    int twoNum = two[j-1] - two[st];
                    if(twoNum > maxi){
                        maxi = twoNum;
                        res = {st+1,j-1};
                    }
                    break;
                }
            }
        }
    }
    cout<<res.first-1<<" "<<n-res.second<<endl;
}

int main()
{
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
