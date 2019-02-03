#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
node *construct_node(int data)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}
void append(node **head_ref,int data)
{
    if(*head_ref==NULL)
    {
        *head_ref=construct_node(data);
        return;
    }
    node *local=*head_ref;
    while(local->next!=NULL)
        local=local->next;
    local->next=construct_node(data);
}
void sortedInsert(node **head_ref,int data)
{
    node *tmp=(node *)malloc(sizeof(node));
    node *prev;
    tmp->data=data;
    if(*head_ref==NULL)
    {
        tmp->next=NULL;
        *head_ref=tmp;
        return;
    }
    node *local=*head_ref;
    while(local->data<=data&&local!=NULL){
        prev=local;
        local=local->next;}
    if(local->data>data)
    {
        tmp->next=prev->next;
        prev->next=tmp;
    }
    if(local==NULL)
    {
        prev->next=tmp;
        tmp->next=NULL;
    }
}
int count_occur(node *head,int data)
{
    int count1=0;
    while(1)
    {
        if(head==NULL)
            break;
        if(head->data==data)
            count1++;
        head=head->next;
    }
    return count1;
}
int GetNth(node *head,int pos)
{
    while(pos--)
        head=head->next;
    return head->data;
}

void display(node *head)
{
    if(head==NULL)
        return;
    cout << head->data <<endl;
    display(head->next);
}

void DeleteList(node **head_ref)
{
    node *local=*head_ref;
    while(local!=NULL)
    {
        node *tmp=local;
        local=local->next;
        free(tmp);
    }
    *head_ref=NULL;
}
int pop(node **head_ref)
{
    node *local=*head_ref;
    assert(local!=NULL);
    *head_ref=local->next;
    int data=local->data;
    free(local);
    local=NULL;
    return data;
}

void atfront(node **head_ref,int data)
{
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void insertNth(node **head_ref,int pos,int data)
{
    if(pos==0)
        atfront(head_ref,data);
    else{
        node *prev=*head_ref;
        node *new_node=(node *)malloc(sizeof(node));
        new_node->data=data;
        while(--pos){assert(prev);
            prev=prev->next;}
        assert(prev);
        new_node->next=prev->next;
        prev->next=new_node;
    }
}

void reverse_list(node **head_ref)
{
    node *local=*head_ref;
    node *next,*result=NULL;
    while(local!=NULL)
    {
        next=local->next;
        local->next=result;
        result=local;
        local=next;
    }
    *head_ref=result;
}

int main()
{
    node *head=NULL;
    int n;
    cin >> n;
    while(n--)
    {
        int d;
        scanf("%d",&d);
        append(&head,d);
    }
    insertNth(&head,5,45654);
    reverse_list(&head);
    display(head);

}
