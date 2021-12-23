//博弈论
//1、找规律
//当n为奇数时，先手必胜。证明：无法在连续两手后有人获胜。
//若先手带走的数字为a后异或和为b，则后手要带走的数字必须要为b，且a!=b
//那么如果先手后都是必败态，则对于1<=i<=n,(ai和bi)成对出现，则n为偶数，矛盾。
//依次减少2个数字，也是上述情况。直到剩余最后一个数字，由先手者拿走。
//当n为偶数时，如果先手者无法找到一个数，使得剩下的数字异或和为0，则必败（后手者到了上面的必胜态）

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int tot = 0;
    set<int> st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
        tot ^= a[i];
    }
    if(n%2==1){
        cout<<"Win"<<endl;
        return 0;
    }

    if(st.count(tot)){
        cout<<"Win"<<endl;
        return 0;
    }
    cout<<"Lose"<<endl;
    return 0;
}

//2、暴力打表找规律（会TLE，只能用作测试简单case）
#include<bits/stdc++.h>
using namespace std;

bool isLose(vector<int> as){
    int all_xor = 0;
    for(int a:as){
        all_xor ^= a;
    }
    if(!all_xor){
        return true; //当前失败
    }

    for(int i=0;i<as.size();i++){
        vector<int> tmp;
        for(int j=0;j<as.size();i++){
            if(i!=j){
                tmp.push_back(as[j]);
            }
        }
        if(isLose(tmp)){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool res = isLose(a);
    if res{
        cout<<"Lose"<<endl;
        return 0;
    }
    cout<<"Win"<<endl;
    return 0;
}