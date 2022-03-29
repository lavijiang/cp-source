#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(200002);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int up = -1;
    for(int i = 0;i<200002;i++){
        if(b[i] == 0){
            up = i;
            break;
        }
    }

    set<int> st;
    vector<int> res;
    int newup = up;
    for(int i = 0;i<n;i++){
        if(a[i]<up){
            st.insert(a[i]);
            b[a[i]]--;
            if(b[a[i]] == 0){
                newup = min(newup,a[i]);
            }
        }
        if(st.size() == up){
            res.push_back(up);
            up = newup;
            st.clear();
        }
    }
    cout<<res.size()<<endl;
    for(int a:res){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
