#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

struct adjlist{
    node *head;
};
struct Graph{
    int v;
    adjlist *array1;
};
Graph *build_graph(int v)
{
    Graph *graph=(Graph *)malloc(sizeof(Graph));
    graph->array1=(adjlist *)malloc(v*sizeof(adjlist));
    graph->v=v;
    for(int i=0;i<v;i++)
        graph->array1[i].head=NULL;
    return graph;
}

void addedge(Graph **graph_ref,int src,int dest)
{
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=dest;
    new_node->next=(*graph_ref)->array1[src].head;
    (*graph_ref)->array1[src].head=new_node;

    new_node=(node *)malloc(sizeof(node));
    new_node->data=src;
    new_node->next=(*graph_ref)->array1[dest].head;
    (*graph_ref)->array1[dest].head=new_node;
}


int main()
{
    int v;
    scanf("%d",&v);
    Graph *graph=build_graph(v);
    addedge(&graph,0,1);
    addedge(&graph,0,2);
    addedge(&graph,1,2);
    addedge(&graph,1,3);
    addedge(&graph,1,4);
    addedge(&graph,2,6);
    addedge(&graph,2,7);
    addedge(&graph,2,4);
    addedge(&graph,3,4);
    addedge(&graph,4,5);

}
