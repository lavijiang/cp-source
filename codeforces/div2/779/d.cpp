#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int p[N], cnt[32][2];
 
void solve() {
    memset(cnt, 0, sizeof cnt);
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; ++i) {
    	int x; cin >> x;
    	for (int j = 0; j <= 30; ++j, x >>= 1)
    		cnt[j][x & 1]++;
    }
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
    	ans |= ((cnt[i][0] < cnt[i][1]) * (1 << i));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
