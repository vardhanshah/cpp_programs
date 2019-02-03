#include<iostream> 
#include<list>
#include<stack>

using namespace std;

class Graph
{
	int v;
	list<int> *adj;
	
	void fillorder(int v,bool visited[],stack<int> &s);
	void DFSUtil(int v,bool visited[]);
	public:
		Graph(int v);
		
		void addedge(int v,int w);
		
		void printSSC();
		
		Graph getTranspose();
};



Graph::Graph(int v)
{
	this->v=v;
	adj = new list<int>[v];
}
void Graph::addedge(int v,int w)
{
	adj[v].push_back(w);
}


void Graph::fillorder(int v,bool visited[],stack<int> &s)
{
	visited[v]=true;
	
	list<int>::iterator i;
	
	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i])
			fillorder(*i,visited,s);
	
	s.push(v);
	cout << s.top() << " ";
}

void Graph::DFSUtil(int v,bool visited[])
{
	visited[v]=true;
	cout << v << " ";
	list<int>::iterator i;
	
	for(i=adj[v].begin();i!=adj[v].end();i++)
		if(!visited[*i])
			DFSUtil(*i,visited);
}



Graph Graph::getTranspose()
{
	Graph gr(this->v);
	
	list<int>::iterator i;
	for(int j=0;j<v;j++)
		for(i = this->adj[j].begin();i!=this->adj[j].end();i++)
			gr.adj[*i].push_back(j);
		
	return gr;
}

void Graph::printSSC()
{
	bool visited[v];
	stack<int> s;
	for(int i=0;i<v;i++)
		visited[i]=false;
		
	for(int i=0;i<v;i++)
		if(!visited[i])
			fillorder(i,visited,s);
	cout << endl;
	for(int i=0;i<v;i++)
		visited[i]=false;
	
	Graph gr = getTranspose();
	
	while(!s.empty())
	{
		int temp = s.top();
		s.pop();
		
		if(!visited[temp])
		{
			gr.DFSUtil(temp,visited);
			cout << endl;
		}
	}
}
		

int main()
{
	Graph g(5);
	
	g.addedge(3,4);
	g.addedge(2,3);
	g.addedge(4,2);
	g.addedge(1,0);
	g.addedge(1,2);
	
	g.printSSC();
}
