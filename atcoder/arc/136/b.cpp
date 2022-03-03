//前提当然是A B是两个相同的set
//结论：swap一个序列的两个数字,会改变序列逆序数的奇偶性 (很容易证明)
//题目中的变换相当于两次swap操作
//1.当A中无重复元素 那么A B必须有相同的逆序对奇偶性
//2.当A中有重复元素,必然ok(先mark成都不重复，如果1无法成立，swap相同元素即可)

#include <bits/stdc++.h>
#define N 5010
using namespace std;
int n,a[N],b[N];
int sum1=0,sum2=0;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    multiset<int>A,B;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        A.insert(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        B.insert(b[i]);
    }
    if(A!=B)
    {
        cout<<"No";
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(A.count(a[i])>=2)
        {
            cout<<"Yes";
            return 0;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])sum1++;
            if(b[i]>b[j])sum2++;
        }
    }
    if((sum1&1)==(sum2&1))cout<<"Yes";
    else cout<<"No";
    return 0;
}
