// 0 indxed nodes
#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

typedef pair<int,int> pii;

vector<vector<pii> >graph;

int n,m;
void show()
{
	for(int i=0;i<n;i++)
	{
		cout << i <<":" ;
		for(int j=0;j<graph[i].size();j++)
			cout << " \t" << graph[i][j].first << " " << graph[i][j].second << endl;
		cout << endl;
	}
}
// constructing MST assuming Graph is connected 
long consturct_MST(vector<pii> &dist,int s)
{
	vector<bool> visited(n,false);
	for(int i=0;i<dist.size();i++)
		{dist[i].first=-1;
		dist[i].second=INF;}
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	long total=0;
	pq.push({0,s});
	
	while(!pq.empty())
	{
		int u=pq.top().second;
		int d=pq.top().first;
		pq.pop();
		cout  << u << endl;
		if(visited[u])
			continue;
		total+=d;
		visited[u]=true;
		for(int i=0;i<graph[u].size();i++)
		{
			int v = graph[u][i].first;
			if(visited[v])
				continue;
			int cost = graph[u][i].second;
			if(cost<dist[v].second)
			{
				dist[v].second = cost;
				 dist[v].first = u;
				 pq.push({cost,v});
			}
		}
	}
	return total;
}			
			
int main()
{
	ifstream in("read.txt");
	in >> n >> m;
	graph.resize(n);
	for(int i=0;i<n;i++)
		graph[i].resize(0);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		in >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	vector<pii> mst(n);

	long mst_w = consturct_MST(mst,2);
	for(int i=0;i<n;i++)
		cout << i << "\t" << mst[i].first << endl;
	cout << mst_w << endl;
	return 0;
}
	
