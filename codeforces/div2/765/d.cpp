//trie树
//树节点存储最大的set树个数和上一个转移的父节点id
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *ch[2];
    pair<int, int> v;
    Node() : ch{}, v(-1, -1) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    
    Node *root = new Node();
    vector<pair<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = {1, -1};
        auto t = root;
        //找到这个数可以组合成set的最大个数
        for (int j = 29; j >= 0 && t != nullptr; j--) {
            int d = a[i].first >> j & 1;
            if (~k >> j & 1) { //k的第j位是0 
                if (t->ch[!d] != nullptr) { //取一位不一样的即可
                    dp[i] = max(dp[i], t->ch[!d]->v);
                }
                t = t->ch[d];
            } else { //k的第j位是1
                t = t->ch[!d]; //那么必须是走不一样的子路径
            }
        }
        if (t != nullptr) {
            dp[i] = max(dp[i], t->v);
        }
        auto v = pair(dp[i].first + 1, i);
        
        //把最大值更新到这个数的trie树上
        t = root;
        t->v = max(t->v, v);
        for (int j = 29; j >= 0; j--) {
            int d = a[i].first >> j & 1;
            if (t->ch[d] == nullptr) {
                t->ch[d] = new Node();
            }
            t = t->ch[d];
            t->v = max(t->v, v);
        }
    }
    
    int i = max_element(dp.begin(), dp.end()) - dp.begin();
    if (dp[i].first == 1) {
        cout << "-1\n";
    } else {
        cout << dp[i].first << "\n";
        while (i != -1) {
            cout << a[i].second + 1 << " \n"[dp[i].second == -1];
            i = dp[i].second;
        }
    }
    
    return 0;
}