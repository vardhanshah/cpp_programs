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

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int gcd_array(vector<int> &a)
{
	int result=a[0];
	ford(i,1,sz(a))
		result=gcd(result,a[i]);
	return result;
}
int lcm(int a,int b)
{
	return abs((a/gcd(a,b))*b) ;
}
int main(int argc, char **argv)
{
	optimize;
	int a=-15,b=4;
	cout << a%b << endl;
	cout << gcd(a,b) << "  "<< lcm(a,b) << endl;
	int l[]={2,4,6,8,10};
	vi p(l,l+5);
	cout << gcd_array(p) << endl;
	return 0;
}


