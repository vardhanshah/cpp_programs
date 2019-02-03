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
#define MAX 100000
const int mod=1000000007;

typedef int64_t ll;

typedef pair<int,int> pii;
//typedef tuple<int,int,int> tii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vector<vector<pii> > graph;

int main(int argc, char **argv)
{
	optimize;
	int n,edges;
	cin >> n >> edges;
	graph.resize(n);
	ford(i,0,edges)
	{
		int u,v,w;
		cin >> u >> v >> w;
		u--,v--;
		graph[u].pb(mp(v,w));// first node index and second weight 
	}
	
	vector<int> m(n);
	int s,t;
	cin >> s >> t;s--;t--;
	m[t]=0;
	ford(i,0,n)
		if(i!=t)
			m[i]=MAX;
	bool f=0;
	ford(u,0,n)
	{
		if(u==t)
			continue;
		f=0;
		ford(v,0,sz(graph[u]))
			if(graph[u][v].fi==t)
			{
				f=1;
				m[u]=graph[u][v].se;
				break;
			}
		if(!f)
			m[u]=MAX;
	}

	ford(i,2,n)
		ford(u,0,n)
			if(u!=t)
			{
				ford(v,0,sz(graph[u]))
					m[u]=min(m[u],graph[u][v].se+m[graph[u][v].fi]);
			}
	cout << m[s] << endl;
			
	return 0;
}


