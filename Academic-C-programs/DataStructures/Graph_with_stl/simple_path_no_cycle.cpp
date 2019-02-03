#include<bits/stdc++.h>

using namespace std;

class Graph{
	int v;
	vector<vector<int> > adj;
	bool **included;
	public:
		Graph(int v);
		void edge(int u,int v);
		void show(void);
		void path(int s,int t);
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
void Graph::path(int s,int t)
{
	if(s==t)
	{
		cout << "source and destination nodes are same" << endl;
		return;
	}
	vector<int> q;
	deque<int> ans;ans.push_back(t);
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	q.push_back(s);
	int tmp=s;
	int pos=1;
	visited[s]=true;
	bool flag=0;
	while(!flag)
	{
		for(int i=0;i<adj[tmp].size();i++)
		{
			if(!visited[adj[tmp][i]])
			{
				visited[adj[tmp][i]]=true;
				if(adj[tmp][i]==t)
					flag=1;
				q.push_back(adj[tmp][i]);
			}
		}
		tmp=q[pos++];
	}
	for(int i=0;i<q.size();i++)
		cout << q[i] << endl;
	bool f=0;int search;
	for(int i=q.size()-1;i>0;)
	{
		f=0;
		search=q[i];
		for(int j=i-1;j>=0;j--)
		{
			//cout << "j:\t" << j << "\t" <<  q[j] << endl;
			for(int k=0;k<adj[q[j]].size();k++)
			{
				
				if(adj[q[j]][k]==search)
				{
					f=1;
					ans.push_front(q[j]);
					//cout << "%%%%%" << adj[q[j]][k] << "\t" << search << endl;
					i=j;
					break;
				}
			}
			if(f==1)
				break;
		}
	}
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
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
		
int main()
{
	//int n;
	//cin >> n ;
	Graph g(9);
	g.edge(0,1);
	g.edge(1,2);
	g.edge(1,8);
	g.edge(2,7);
	g.edge(2,3);
	g.edge(3,4);
	g.edge(4,6);
	g.edge(6,5);
	/*for(int i=0;i<n-1;i++)
	{
		int p,q;
		cin >> p >> q;
		g.edge(--p,--q);
	}*/
	g.show();
	g.path(1,7);
	return 0;
}

