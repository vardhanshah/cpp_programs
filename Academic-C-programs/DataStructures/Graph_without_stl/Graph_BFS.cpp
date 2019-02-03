#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
FILE *in = fopen("new","r");
FILE *out = fopen("output","w");
struct queue{
    int data;
    queue *next;
    queue *prev;
};
queue *front=NULL,*rear=NULL;
queue *build(int data)
{
    queue *tmp = (queue *)malloc(sizeof(queue));
    tmp->data=data;
    tmp->next=tmp->prev=NULL;
    return tmp;
}
void insert(queue **head_ref,int data)
{
    if(*head_ref==NULL)
    {
        *head_ref=build(data);
        front=rear=*head_ref;
        return;
    }
    queue *new_node = build(data);
    rear->next=new_node;
    new_node->prev=rear;
    rear=rear->next;
    return;
}

int remove(queue **head_ref)
{
    if(*head_ref==NULL)
    {
        printf("Nothing to remove\n");
        front=rear=NULL;
        return 0;
    }
    *head_ref=front->next;
    if(*head_ref!=NULL)
    (*head_ref)->prev=NULL;
    int d = front->data;
    free(front);
    front=*head_ref;
    return d;
}

void show(queue *head)
{
    if(head==NULL){printf("Nothing to show");
        return;}
    fprintf(stdout,"%d\n",head->data);
    show(head->next);
}

/*int main()
{
	queue *head = NULL;
	int n;
	fscanf(in,"%d",&n);
	for(int i=0;i<n;i++)
	{
		int d;
		fscanf(in,"%d",&d);
		insert(&head,d);
	}
	for(int i=0;i<n-1;i++)
		remove(&head);
	show(head);
}*/

struct adj_node{
    int dest;
    adj_node *next;
};

struct adj_list{
    adj_node *head;
};

struct Graph{
    int v;
    adj_list *array;
};

Graph *construct(int v)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->v=v;
    graph->array=(adj_list *)calloc(v,sizeof(Graph));
    for(int i=0;i<v;i++)
        graph->array[i].head=NULL;
    return graph;
}

void addedge(Graph **graph,int src,int dest)
{
    adj_node *node = (adj_node *)malloc(sizeof(adj_node));
    node->dest=dest;
    node->next=(*graph)->array[src].head;
    (*graph)->array[src].head=node;

    node = (adj_node *)malloc(sizeof(adj_node));
    node->dest=src;
    node->next=(*graph)->array[dest].head;
    (*graph)->array[dest].head=node;
}

void show_graph(Graph *graph)
{
	for(int i=0;i<graph->v;i++)
	{
		printf("%d:\t",i);
		adj_node * node=graph->array[i].head;
		while(node!=NULL)
		{
			printf("%d ",node->dest);
			node=node->next;
		}
		printf("\n");
	}
}

int explore(Graph *graph,int *disc,queue **top_ref)
{
	if((*top_ref) == NULL)
		return 0;
	adj_node *node = graph->array[(*top_ref)->data].head;
	
	while(node!=NULL)
	{
		if(disc[node->dest]==0)
		{
			printf("%d ",node->dest);
			insert(top_ref,node->dest);
			disc[node->dest]=1;
		}
		node=node->next;
	}
	remove(top_ref);
	return 1;
}

void BFS(Graph *graph,int src)
{
	queue *head=NULL;
	int *disc = (int *)malloc((graph->v)*sizeof(int));
	for(int i=0;i<(graph->v);i++)
		disc[i]=0;
	disc[src]=1;
	insert(&head,src);
	printf("\nBFS:\t");
	printf("%d ",src);
	while(1)
		if(!explore(graph,disc,&head))
			break;
}


	
int main()
{
    int v;
    scanf("%d",&v);
    Graph *graph = construct(v);
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
	show_graph(graph);
	BFS(graph,5);
}















