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
#define dist(a,b) sqrt((a.fi-b.fi)*(a.fi-b.fi) + (a.se-b.se)*(a.se-b.se))
const int mod=1000000007;

typedef long long ll;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

bool compx(pii a,pii b)
{
	return a.fi < b.fi;
}
bool compy(pii a,pii b)
{
	return a.se < b.se;
}

class point{
	vector<pii> p;
	public:
		int n;
		pair<pii,pii> closestPair;
		double closestDistance=INT_MAX;
		vector<pii> xsorted;
		vector<pii> ysorted;
		point(){n=0;}
		point(int n)
		{
			this->n=n;
		}
		void input(void);
		void divide_conquer(int l,int h);
		void brute_force(int l,int h);
};
void point::input(void)
{
	p.resize(n);
	ford(i,0,n)
		cin >> p[i].fi >> p[i].se;
	xsorted=p;
	ysorted=p;
	sort(all(xsorted),compx);
	sort(all(ysorted),compy);
}
void point::brute_force(int l,int h)
{
	double tmp;
	for(int i=l;i<=h;i++)
		for(int j=i+1;j<=h;j++)
		{
			tmp=dist(xsorted[i],xsorted[j]);
			if(closestDistance>tmp)
			{
				closestDistance=tmp;
				closestPair=mp(xsorted[i],xsorted[j]);
			}
		}
}
void point::divide_conquer(int l,int h)
{
	if(h-l<=2)
		return brute_force(l,h);
	int mid=(h-l+1)/2;
	pii midPoint = xsorted[mid];
	divide_conquer(l,mid);
	divide_conquer(mid+1,h);
	
	
	vector<pii> strip;
	for(int i=0;i<n;i++)
		if(ysorted[i].fi>=l&&ysorted[i].fi<=h&&fabs(ysorted[i].fi-midPoint.fi)<closestDistance)
			strip.push_back(ysorted[i]);
	double temp;
	for(int i=0;i<sz(strip);i++)
	for(int j=i+1;j<sz(strip)&&strip[j].se-strip[i].se<closestDistance;j++)
	{
		temp=dist(strip[i],strip[j]);
		if(temp<closestDistance)
		{
			closestDistance=temp;
			closestPair=mp(strip[i],strip[j]);
		}
	}
}
	
int main(int argc, char **argv)
{
	optimize;
	point a;
	cin >> a.n;
	cout << a.n;
	a.input();
	a.divide_conquer(0,a.n-1);
	cout << a.closestDistance << endl;
	cout << "point x:" << " " << a.closestPair.fi.fi << " " << a.closestPair.fi.se << endl;
	cout << "point y:" << " " << a.closestPair.se.fi << " " << a.closestPair.se.se << endl;
	return 0;
}

