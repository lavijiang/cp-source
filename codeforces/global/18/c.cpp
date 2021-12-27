#include<bits/stdc++.h>
using namespace std;
const int I=1e9;
string s,t;
int T,n,x,y,z,A;
int main()
{
	cin>>T;
	while(T--&&cin>>n>>s>>t)
	{
		x=y=z=0,A=I;
		for(int i=0;i<n;i++)
			x+=s[i]-'0',y+=t[i]-'0',z+=s[i]!=t[i];
		if(x==y)
			A=z; //交换01，即交换不等的个数（为偶数次）
		if(x==n-y+1)
			A=min(A,n-z); //先选择（1->1），再选择不等的个数 选择（1->0）无意义，如果最终需要从1变为0，那么不选这个数对，最终经过奇数次变换也能达到目的
		cout<<(A==I?-1:A)<<'\n';
	}
    return 0;
}