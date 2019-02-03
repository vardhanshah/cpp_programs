#include<bits/stdc++.h>

using namespace std;
int **dp;
int coin_change(int *c,int sum,int n)
{
	if(sum==0)
		return 1;
	if(sum<0)
		return 0;
	if(sum>0&&n<=0)
		return 0;
	return coin_change(c,sum,n-1) + coin_change(c,sum-c[n],n);
}

int main()
{
	int n,sum;
	cin >> n >> sum;
	int c[n+1];
	dp=new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=new int[sum+1];
	for(int i=1;i<=n;i++)
		cin >> c[i];
	cout << coin_change(c,sum,n);
	return 0;
}
	
	
