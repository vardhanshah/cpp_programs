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

int main(int argc, char **argv)
{
	optimize;
	int n;
	cin >> n;
	vi a(n);
	a.resize(n);
	ford(i,0,n)
		cin >> a[i];
	int sum=0,best=0;
	ford(i,0,n)
	{
		sum=max(a[i],sum+a[i]);
		best=max(best,sum);
	}
	cout << best << endl;
	return 0;
}


