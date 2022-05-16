// 1、有环路(拓扑排序https://www.acwing.com/solution/content/21908/)
// 2、存在一条路径大于等于k-1
#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    i64 k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    
    int l = 0, r = 1E9 + 1;
    while (l < r) {
        int x = (l + r) / 2;
        int cnt = 0;
        vector<int> deg(n), q; //入度和起始节点的队列 使用拓扑排序找环
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                continue;
            }
            cnt++;
            for (auto v : adj[i]) {
                if (a[v] <= x) {
                    deg[v]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] <= x && !deg[i]) {
                q.push_back(i);
            }
        }
        
        vector<int> dp(n); //以节点i为起点的路径最大长度
        for (int i = 0; i < int(q.size()); i++) {
            int u = q[i];
            dp[u] = max(dp[u], 1);
            for (auto v : adj[u]) {
                if (a[v] > x) {
                    continue;
                }
                dp[v] = max(dp[v], dp[u] + 1); //更新长度
                if (!--deg[v]) {
                    q.push_back(v);
                }
            }
        }
        
        if (cnt > int(q.size()) || *max_element(dp.begin(), dp.end()) >= k) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    
    if (r > 1E9) {
        cout << "-1\n";
    } else {
        cout << r << "\n";
    }
    
    return 0;
}