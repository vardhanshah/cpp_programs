#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<iostream>

using namespace std;
FILE *in = fopen("new","r");
FILE *out = fopen("output","w");

struct stack{
	int data;
	stack *next;
};

stack *build(int data)
{
	stack *st = (stack *)malloc(sizeof(stack));
	st->data=data;
	st->next=NULL;
	return st;
}

void push(stack **head_ref,int data)
{
	stack *node = build(data);
	if(*head_ref == NULL)
	{
		*head_ref=node;
		return;
	}
	node->next=*head_ref;
	*head_ref=node;
}

int pop(stack **head_ref)
{
	if(*head_ref==NULL)
	{
		printf("Nothing to delete");
		return 0;
	}
	stack *local = *head_ref;
	*head_ref=local->next;
	int d = local->data;
	free(local);
	local=NULL;
	return d;
}
void show(stack *head)
{
	if(head==NULL)
		return;
	printf("%d ",head->data);
	show(head->next);
}

/*int main()
{
	stack *head = NULL;
	int n;
	fscanf(in,"%d",&n);
	for(int i=0;i<n;i++)
	{
		int d;
		fscanf(in,"%d",&d);
		push(&head,d);
	}
	for(int i=0;i<n-1;i++)
		pop(&head);
	show(head);
}*/		

struct adj_node
{
	int dest;
	adj_node *next;
};	

struct adj_list
{
	adj_node *head;
};

struct graph
{
	int v;
	adj_list *array;
};

graph *construct(int v)
{
	graph *tmp = (graph *)malloc(sizeof(graph));
	tmp->v=v;
	tmp->array = (adj_list *)malloc(v*sizeof(adj_list));
	for(int i=0;i<v;i++)
		tmp->array[i].head = NULL;
	return tmp;
}
		
void addedge(graph **tmp,int src,int dest)
{
	adj_node *node = (adj_node *)calloc(1,sizeof(adj_node));
	node->dest = dest;
	node->next=(*tmp)->array[src].head;
	(*tmp)->array[src].head=node;
	
	node = (adj_node *)calloc(1,sizeof(adj_node));
	node->dest = src;
	node->next = (*tmp)->array[dest].head;
	(*tmp)->array[dest].head=node;
}

void show_graph(graph *tmp)
{
	for(int i=0;i<tmp->v;i++)
	{
		printf("%d:\t",i);
		adj_node *node = tmp->array[i].head;
		while(node!=NULL)
		{
			printf("%d ",node->dest);
			node=node->next;
		}
		printf("\n");
	}
}

void explore(graph *tmp,int *disc,stack **st_ref)
{
	
	adj_node *node = tmp->array[(*st_ref)->data].head;
	while(node!=NULL)
	{
		if(disc[node->dest]==0)
		{
			push(st_ref,node->dest);
			printf("%d ",node->dest);
			disc[node->dest]=1;
			explore(tmp,disc,st_ref);
		}
		node = node->next;
	}
	pop(st_ref);
}


void DFS(graph *tmp,int src)
{
	int *disc = (int *)calloc(tmp->v,sizeof(int));
	for(int i=0;i<tmp->v;i++)
		disc[i]=0;
	stack *head = NULL;
	push(&head,src);
	printf("\nDFS\n");
	printf("%d ",src);
	
	explore(tmp,disc,&head);
}

		
int main()
{
    int v;
    scanf("%d",&v);
    graph *tmp = construct(v);
    addedge(&tmp,0,1);
    addedge(&tmp,0,2);
    addedge(&tmp,1,2);
    addedge(&tmp,1,3);
    addedge(&tmp,1,4);
    addedge(&tmp,2,6);
    addedge(&tmp,2,7);
    addedge(&tmp,2,4);
    addedge(&tmp,3,4);
    addedge(&tmp,4,5);
	show_graph(tmp);
	DFS(tmp,0);
}		
		
		
		
		
		
		
		 








