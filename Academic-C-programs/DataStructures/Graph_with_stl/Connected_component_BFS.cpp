#include<bits/stdc++.h>

using namespace std;

class Connected_component
{
	protected:
	int n;
	vector<vector<int> > c;
};

class Graph : public Connected_component
{
	int v;
	vector<vector<int> > adj;
	bool **included;
	public:
		Graph(int v);
		void edge(int u,int v);
		void show(void);
		void components(void);
};

Graph::Graph(int n)
{
	v=n;
	adj.resize(n);
	included = (bool **)calloc(n,sizeof(bool *));
	for(int i=0;i<n;i++)
	{
		adj[i].resize(0);
		included[i] = new bool[n];
	}
}
void Graph::edge(int p,int q)
{
	if(!included[p][q])
	{
		adj[p].push_back(q);
		included[p][q]=1;
	}
	if(!included[q][p])
	{
		adj[q].push_back(p);
		included[q][p]=1;
	}
}
void Graph::show(void)
{
	for(int i=0;i<v;i++)
	{
		cout << i << ":\t";
		for(int j=0;j<int(adj[i].size());j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}
int check(bool *visited,int n)
{
	for(int i=0;i<n;i++)
		if(!visited[i])
			return i;
	return -1;
}
void Graph::components(void)
{
	bool visited[v];
	memset(visited,false,v);
	int pos;
	queue<int> q;
	while((pos=check(visited,v))!=-1)
	{
	//	cout << "pos:\t" << pos << endl; 
		vector<int> v;
		q.push(pos);
		visited[pos]=true;
		v.push_back(pos);
		while(!q.empty())
		{
			for(int i=0;i<int(adj[pos].size());i++)
			{
				if(!visited[adj[pos][i]])
				{
					q.push(adj[pos][i]);
					v.push_back(adj[pos][i]);
					visited[adj[pos][i]]=true;
				}
			}
			q.pop();
			pos=q.front();
		}
		c.push_back(v);
	}
	for(int i=0;i<int(c.size());i++)
	{
		for(int j=0;j<int(c[i].size());j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	n=c.size();
}
		
int main()
{
	Graph g(14);
	g.edge(0,1);
	g.edge(1,2);
	g.edge(1,3);
	g.edge(2,3);
	g.edge(2,4);
	g.edge(2,5);
	g.edge(3,5);
	g.edge(3,7);
	g.edge(3,8);
	g.edge(4,5);
	g.edge(5,6);
	g.edge(7,8);
	g.edge(9,10);
	g.edge(11,12);
	g.edge(12,13);
	g.show();
	g.components();
	return 0;
}
