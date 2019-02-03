#include<bits/stdc++.h>
using namespace std;
#define INF 1e18L + 5
typedef pair<int,int> ipair;
class Graph{
	
	int v;
	list <pair<int,int> > *adj;
	
	public:
		
		Graph(int v);
		void addEdge(int p,int q,int r);
		int dijkstraSP(int src,int end);
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<ipair> [v];
}

void Graph::addEdge(int p,int q,int weight)
{
	adj[p].push_back(make_pair(q,weight)); // node =v and val = weight;
	adj[q].push_back(make_pair(p,weight));
}
int Graph::dijkstraSP(int src,int end)
{
	vector<int> dist(v,INF);
	dist[src]=0;
	priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
	pq.push(make_pair(0,src));  // val = 0 and node = src;
		
	while(!pq.empty())
	{
		int p = pq.top().second;
		//int val_p = pq.top().first;
		//cout << p << "\t" << val_p << endl;
		pq.pop();
		list<ipair> ::iterator i;
		for(i=adj[p].begin();i!=adj[p].end();i++)
		{
			int q = i->first;
			int val_q = i->second;
			if(dist[q] > dist[p] + val_q)
			{
				dist[q] = dist[p] + val_q;
				//cout << q << "\t" << dist[q] << endl;
				pq.push(make_pair(dist[q],q));
				
			}
		}
	}
	for(int i=0;i<v;i++)
		cout << dist[i] << endl;
	return dist[end];
}

int main()
{
	int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    cout << g.dijkstraSP(1,6);
 
    return 0;
}
