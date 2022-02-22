//不妨设 dp[i] 为满足 [2^(i-1),2^i)的数字个数
//则dp[i]中的奇数是由 [2^(i-2),2^(i-1))中的数字通过操作2得来
//dp[i]中的偶数是由 [2^(i-3),2^(i-2))中的数字通过操作3得来
//当然还需要注意序列A中可以衍生的数字，这些需要排除，并在计算过程中加上非衍生的数字

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set <int> useful;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        bool flag = false;
        while (x > 0) {
            if (useful.count(x)) {
                flag = true;
                break;
            }
            if (x & 1) {
                x >>= 1;
            } else if (x & 2) {
                //无法由2 3 操作转换而来
                break;
            } else {
                x >>= 2;
            }
        }
        if (!flag)
            useful.insert(a[i]);
    }
    vector <int> cnt(30, 0), dp(p);
    for (int x : useful) {
        cnt[__lg(x)]++;
    }
    int ans = 0;
    for (int i = 0; i < p; ++i) {
        if (i < 30) {
            dp[i] = cnt[i];
        }
        if (i >= 1) {
            dp[i] += dp[i - 1];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        if (i >= 2) {
            dp[i] += dp[i - 2];
            if (dp[i] >= mod) {
                dp[i] -= mod;
            }
        }
        ans += dp[i];
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
}
