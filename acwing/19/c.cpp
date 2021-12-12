#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k,a;
const int N = 200010;
int maxn,minn;
vector<int> s(N);

int get(int j){
    return s[maxn] - s[j-1];
}

int main()
{
    cin>>n>>k;
    maxn = 0,minn = N;
    for (int i = 0; i < n; i ++ ){
        cin>>a;
        s[a]++;
        maxn = max(a,maxn);
        minn = min(a,minn);
    }
    for (int i = 1; i <= maxn; i ++ ){
        s[i] += s[i-1];
    }
    int res = 0;
    for(int i = maxn;i>minn;){
        int tmp = 0;
        while(i>minn&&tmp+get(i)<=k){
            tmp += get(i--);
        }
        res++;
    }
    cout<<res;
    return 0;
}