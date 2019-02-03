#include <bits/stdc++.h>
using namespace std;
#define ford(i,s,e) for(int i=s;i<e;i++)
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int(a.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair 
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define vpresent(c,elt) (find(all(c),elt)!=c.end())
#define present(c,elt) (c.find(elt) != c.end())
#define optimize ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod=1000000007;

typedef int64_t ll;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int opt(int i,int w,vi &weight)
{
	if(i<=0||w<=0)
		return 0;
	if(weight[i]>w)
		return opt(i-1,w,weight);
	return max(opt(i-1,w,weight),weight[i]+opt(i-1,w-weight[i],weight));
}

int main(int argc, char **argv)
{
	optimize;
	int n,w;
	cin >> n >> w;
	vi weight(n+1);
	vi value(n+1);
	ford(i,1,n+1)
		cin >> weight[i];
	ford(i,1,n+1)
		cin >> value[i];
	int dp[n+1][w+1];
	ford(i,0,w+1)
		dp[0][i]=0;
	ford(i,1,n+1)
		ford(j,0,w+1)
			if(weight[i]<=j)
				dp[i][j]=max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
	cout << dp[n][w] << endl;
	return 0;
}


