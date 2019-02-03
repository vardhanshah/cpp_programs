
#include<bits/stdc++.h>

using namespace std;
#define MAX INT_MAX

struct node
{
	int elt;
	int val;
};

class minheap
{
	int size;
	vector<node> h;
	vector<int> pos;
	public:
	minheap(int n);
		void insert(node p);// to take input and store it in vector
		void decreasekey(int p,int val);// to decrease key of node
		void heapify_up(int i);// to check liable place for taken input and make the storage of vector in order(logically in binary heap)
		void show();// to print the members of vector
		void heapify_down(int j);// to make heap in order 
		node extractmin();// to extract the root member of heap
		int height();
		bool empty();
		void pos_show();
		bool inheap(int elt);
};	

minheap::minheap(int n)
{
	pos = vector<int>(n);
}

bool minheap::empty()
{
	return h.size();
}
void swap(node &t,node &y)
{
	node tmp =t;
	t=y;
	y=tmp;
}

void minheap::heapify_up(int i)
{
	while(i && h[i].val<h[(i-1)/2].val)
	{
		pos[h[i].elt] = (i-1)/2;
		pos[h[(i-1)/2].elt] = i;
		swap(h[i],h[(i-1)/2]);
		i=(i-1)/2;
	}
}

void minheap::insert(node p)
{
	h.push_back(p);
	pos[p.elt]=h.size()-1;
	heapify_up(h.size()-1);
}

void minheap::heapify_down(int i)
{
	int smallest,left,right;
	smallest = i;
	left = 2*i + 1;
	right = 2*i + 2;
	if(h[left].val > h[right].val && left < int(h.size()))
		smallest = right;
	else if(h[left].val < h[right].val && right < int(h.size()))
		smallest = left;
	
	if(h[smallest].val > h[i].val)
		smallest = i;
	if(smallest != i)
	{
		pos[h[i].elt]=smallest;
		pos[h[smallest].elt]=i;
		swap(h[smallest],h[i]);
		heapify_down(smallest);
	}

		
}

void minheap::decreasekey(int elt,int val)
{
	h[pos[elt]].val = val;
	heapify_up(pos[elt]);
}

node minheap::extractmin()
{
	if(h.empty())
	{
		node p;p.elt=-1,p.val=-1;
		return p;
	}
	node min = h[0];
	h[0] = h[h.size()-1];h.pop_back();
	pos[h[0].elt] = 0;pos[min.elt]=-1;
	heapify_down(0);
	return min;
}
	


int minheap::height()
{
	if(h.empty())
		return 0;
	int i=0;
	int count=0;
	while((2*i+1) < int(h.size()))
	{
		count++;
		i=2*i+1;
	}
	return count+1;
}

void minheap::show()
{
	for(int i=0;i<int(h.size());i++)
		cout << h[i].elt << ":\t" << h[i].val << endl;
}
void minheap::pos_show()
{
	for(int i=0;i<int(pos.size());i++)
	{
		cout << "node : " << i << " at " << pos[i] << endl;
	}
}
bool minheap::inheap(int elt)
{
	if(pos[elt]==-1)
		return 0;
	return 1;
}
class Graph{
	
	int v;
	list <node> *adj;
	
	public:
		
		Graph(int v);
		void addedge(int p,node q);
		int dijkstraSP(int src,int end);
};

Graph::Graph(int v)
{
	this->v=v;
	adj = new list<node> [v];
}

void Graph::addedge(int p,node q)
{
	node l;l.elt=p;l.val=q.val;
	adj[p].push_back(q);
	adj[q.elt].push_back(l);
}

int Graph::dijkstraSP(int src,int end)
{
	vector<int> dist(v,MAX);
	minheap heap(v);
	node p;
	for(int i=0;i<v;i++)
	{
		p.elt = i;
		p.val = MAX;
		heap.insert(p);
	}
	heap.decreasekey(src,0);
	dist[src]=0;
	while(heap.empty())
	{
		node u = heap.extractmin();
		/*cout << "extractor : " << u.elt << "\t" << endl;*/
		list<node> :: iterator i;
		i = adj[u.elt].begin();
		while(i!=adj[u.elt].end())
		{
			/*cout << "***" <<i->elt << "\t" << i->val << "\n";*/
			if(heap.inheap(i->elt) && dist[u.elt]!=MAX && dist[i->elt] > dist[u.elt] + i->val)
			{
				dist[i->elt] = dist[u.elt] + i->val;
				heap.decreasekey(i->elt,dist[i->elt]);
			}
			i++;
		}
		/*cout << "completed\n";*/
	}
	
	for(int i=0;i<v;i++)
		cout << i << "\t" << dist[i] << endl;
	return dist[end];
}
		
		
		
		

int main()
{

	fstream in;
	in.open("new");
	
	int n;
	cin >> n;

	Graph g(n);
	
	int e;
	cin >> e;
	
	while(e--)
	{
		int p;
		node q;
		cin >> p;
		cin >> q.elt >> q.val;
		g.addedge(p,q);
	}
	
	cout << g.dijkstraSP(0,1);
	
	return 0;
}
