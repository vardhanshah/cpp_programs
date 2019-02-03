#include<bits/stdc++.h>

using namespace std;

class Graph{
	
	int v;
	list<int> *adj;
	vector<string> color;
	public:
		
	Graph(int v);
	void addedge(int v,int w);
	bool CheckBG();
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<int>[v];
	color = vector<string>(v);
}

void Graph::addedge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::CheckBG()
{
	queue<int> q;
	q.push(0);
	bool visited[v];
	visited[0]=1;
	while(!q.empty())
	{
		int val = q.front();
		color[val]="red";
		visited[val]=1;
		list<int>::iterator i;
		for(i=adj[val].begin();i!=adj[val].end();i++)
		{
			if(!visited[*i])
			{
				if(color[val]=="blue")
					color[*i]="red";
				else
					color[*i]="blue";
				visited[*i]=1;
				q.push(*i);
			}
		}
		q.pop();
	}
	list<int>::iterator i;
	for(int j=0;j<v;j++)
	{
		
		for(i=adj[j].begin();i!=adj[j].end();i++)
		{
			if(color[j]==color[*i])
				return 0;
		}
	}

	return 1;
}
	
int main()
{
	Graph g(3);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	if(!g.CheckBG())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	
	
	return 0;
}
