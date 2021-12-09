#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    cin>>n;
    vector<int> num(n);
    vector<int> pre(n);
    cin>>num[0];
    int st = 0;
    int flag = 0;
    for (int i = 1; i < n; i ++ ){
        cin>>num[i];
        if(num[i]>num[i-1]){
            pre[i] = 1;
            if(pre[i-1] == -1){
                flag = 1;
                st = i;
                break;
            }
        }else if(num[i]<num[i-1]){
            pre[i] = -1;
            if(pre[i-1] == 1){
                flag = -1;
                st = i;
                break;
            }
        }else{
            pre[i] = pre[i-1];
        }
    }
    
    if(!flag){
        cout<<0;
        return 0;
    }
    cout<<3<<endl;
    int p = -1;
    for(int i=0;i<st;i++){
        if(flag == 1){
            if(num[i]>num[st-1]){
                p = i;
            }
        }else{
            if(num[i]<num[st-1]){
                p = i;
            }
        }
    }
    cout<<p+1<<" "<<st<<" "<<st+1<<endl;
    return 0;
}
