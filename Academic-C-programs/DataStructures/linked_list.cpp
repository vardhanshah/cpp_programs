#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
void deleting_key(node **head_ref,int key)
{
    node *tmp=*head_ref,*prev;
    if(tmp!=NULL&&tmp->data==key)
    {
        *head_ref=tmp->next;
        free(tmp);
        return;
    }

    while(tmp!=NULL&&tmp->data!=key)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==NULL){
        cout << "NOT FOUND!!" << endl;
        return;}
    prev->next=tmp->next;
    free(tmp);
}
void deleting_node(node **head_ref,int pos)
{
    if(*head_ref==NULL)
        return;
    node *tmp=*head_ref,*prev;
    
    while(pos!=0&&tmp!=NULL)
    {
        prev=tmp;
        tmp=tmp->next;
        pos--;
    }
    if(tmp==NULL)
    {
        cout << "NOT FOUND!";
        return;
    }
    prev->next=tmp->next;
    free(tmp);
}

void append(node **head_ref,int data)
{
    node *local=*head_ref;
    node *new_node=(node *)malloc(sizeof(node));
    new_node->next=NULL;
    new_node->data=data;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(local->next!=NULL)
        local=local->next;

    local->next=new_node;
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout << head->data << endl;
        head=head->next;
    }
}
void atfront(node **head_ref,int data)
{
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}
void insertAfter(node *prev_node,int data)
{

    if(prev_node==NULL)
    {
        cout << "Prev_node cannot be NULL";
        return;
    }
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

int length(node *head)
{
    if(head==NULL)
        return 0;
    return 1+length(head->next);
}
int search(node *head,int key)
{
    if(head==NULL)
        return 0;
    if(head->data==key)
        return 1;
    return search(head->next,key);
}
int main()
{
    int n;
    node *head=NULL;
    append(&head,56);
    append(&head,34);
    atfront(&head,12);
    insertAfter(head->next,123424);
    deleting_key(&head,1);
    int len=length(head);
    display(head);
    if(search(head,1))
        cout << "YES" << endl;
    else
        cout << "NOT FOUND" << endl;
    cout << "****" << len;
    return 0;

}
