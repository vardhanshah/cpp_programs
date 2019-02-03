#include<bits/stdc++.h>

using namespace std;

class Graph{
	int v;
	vector<vector<int> > adj;
	bool cycle_or_not(int i,bool *,bool *);
	public:
		Graph(int n);
		void edge(int a,int b);
		bool cycle_detection(void);
};
Graph::Graph(int n)
{
	v=n;
	adj.resize(n);
	for(int i=0;i<v;i++)
		adj[i].resize(0);
}

void Graph::edge(int a,int b)
{
	adj[a].push_back(b);
}
bool Graph::cycle_or_not(int i,bool *visited,bool *recstack)
{
	cout << i << endl;
	if(visited[i]==false)
	{
		visited[i]=true;
		recstack[i]=true;
		
		for(int j=0;j<adj[i].size();j++)
		{
			if(!visited[adj[i][j]]&&cycle_or_not(adj[i][j],visited,recstack))
				return true;
			else if(recstack[adj[i][j]])
				return true;
		}
	}
	recstack[i]=false;
	return false;
}
bool Graph::cycle_detection(void)
{
	bool *visited,*recstack;
	visited=recstack=new bool[v];
	memset(visited,false,v);
	memset(recstack,false,v);
	
	for(int i=0;i<v;i++)
		if(cycle_or_not(i,visited,recstack))
			return 1;
	return 0;
}
			
int main()
{
	Graph g(4);
	g.edge(0,1);
	g.edge(0,2);
	g.edge(1,2);
	g.edge(3,0);
	g.edge(2,3);
	
	
	if(g.cycle_detection())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
