#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t -- )
    {
        int n, k;
        cin >> n >> k;
        for(int i = n-1;i>0;i--){
             if(k>n-i){
                 k -= n-i;
                 continue;
             }
             string s(n,'a');
             s[i-1] = 'b';
             s[n-k] = 'b';
             cout<<s<<endl;
             break;
        }
    }

    return 0;
}
