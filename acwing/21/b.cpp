#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int tot = 0;
    int pre1 = 0; //当前有多少个1
    for(int i = s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            pre1++;
        }else{
            if(!pre1){
                tot++;
            }else{
                tot++;
                tot += pre1;
                pre1 = 1;
            }
        }
    }
    if(pre1>1){
        tot++;
        tot+=pre1;
    }
    cout<<tot;
    return 0;
}
