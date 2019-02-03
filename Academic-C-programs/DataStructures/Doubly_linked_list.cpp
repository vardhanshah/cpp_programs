#include<bits/stdc++.h>
using namespace std;
FILE *in = fopen("read","r");
struct node{
    int data;
    node *next;
    node *prev;
};

void push_front1(node **head_ref,int data)
{
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=*head_ref;

    if(*head_ref!=NULL)
        (*head_ref)->prev=new_node;

    *head_ref=new_node;
}
void push_back1(node **head_ref,int data)
{
    node *local=*head_ref;
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;}
    while(local->next!=NULL)
        local=local->next;
    local->next=new_node;
    new_node->prev=local;
}
void insertNth(node **head_ref,int pos,int data)
{
    if(pos==0)
        push_front1(head_ref,data);
    else{
    node *local=*head_ref;
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    while(pos--)
        local=local->next;

    local->prev->next=new_node;
    new_node->next=local;
    new_node->prev=local->prev;
    local->prev=new_node;
}
}

void reverse_display(node *head)
{
    if(head==NULL)
        return;
    printf("%d\n",head->data);
    return reverse_display(head->prev);
}
void display(node *head)
{
    if(head==NULL)
        return;
    printf("%d\n",head->data);
    if(head->next==NULL)
    {
        printf("Reversed Display of list:\n");
        reverse_display(head);
    }
    return display(head->next);
}

int pop(node **head_ref)
{
    if(*head_ref==NULL){
        printf("Nothing to pop \n");
        return 0;}
    else{
        node *local=*head_ref;
        *head_ref=local->next;
        if(*head_ref!=NULL)
        (*head_ref)->prev=NULL;
        int data=local->data;
        free(local);
        local=NULL;
        return data;
    }
}
int main()
{
    node *head=NULL;
    node *front,*rear;
    front=rear=NULL;
    int n;
    fscanf(stdin,"%d",&n);
    while(n--)
    {
        int d;
        fscanf(stdin,"%d",&d);
        push_back1(&head,d);
    }
    printf("pop out : %d\n",pop(&head));
    display(head);
}
