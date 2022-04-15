#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> b(n);
    for(int i = 0;i<n;i++) cin>>b[i];

    vector<ll> closed(n); ;//close[i]将在位置i+1处结束的操作数
    ll sum = 0, cnt = 0, ans = 0;//sum目前这位上需要减去的数字 cnt当前存在的操作数  ans总共操作数
    for (int i = n - 1; i >= 0; --i) {
        sum -= cnt;
        cnt -= closed[i];
        b[i] -= sum;
        if (b[i] <= 0) {
            continue;
        }
        int el = min(i + 1, k);
        ll need = (b[i] + el - 1) / el;
        sum += need * el;
        cnt += need;
        ans += need;
        if (i - el >= 0) {
            closed[i - el] += need;
        }
    }
    cout<<ans<<endl;
}

int main() {
    solve();
    return 0;
}
