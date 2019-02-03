#include <bits/stdc++.h>
using namespace std;
#define ford(i,s,e) for(int i=s;i<e;i++)
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int(a.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple 
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rall(c) c.rbegin(),c.rend()
#define vpresent(c,elt) (find(all(c),elt)!=c.end())
#define present(c,elt) (c.find(elt) != c.end())
#define optimize ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mod=1000000007;
 
typedef int64_t ll;
 
typedef pair<int,int> pii;
//typedef tuple<int,int,int> tii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
 
string s1,s2,s3;

int opt(int n,int m)
{
	if(n>=sz(s1)||m>=sz(s2))
		return 0;
	if(s1[n]==s2[m])
		return 1 + opt(n+1,m+1);
	return max(opt(n+1,m),opt(n,m+1));
}

int main(int argc, char **argv)
{
	optimize;
	cin >> s1 >> s2;
	cout << opt(0,0);
	//cout << s3 << endl;
}
