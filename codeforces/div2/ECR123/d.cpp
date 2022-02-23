#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> x(q), y(q);
        for (int i = 0; i < q; i += 1) cin >> x[i] >> y[i];
        set<int> sx, sy;
        LL ans = 1;
        //由于后面的操作会覆盖前面的操作，所以从后往前看每步的操作（倒着做）
        //如果操作可以将颜色保留即是有效的，称为有效操作
        //有效操作为之前没有覆盖这个行或者列 且 颜色没有涂满整个方格(即行和列没有被占满)
        for (int i = q - 1; i >= 0; i -= 1) {
            if ((not sx.contains(x[i]) or not sy.contains(y[i])) and sx.size() < n and sy.size() < m)
                ans = ans * k % mod;
            sx.insert(x[i]);
            sy.insert(y[i]);
        }
        cout << ans << endl;
    }
}
