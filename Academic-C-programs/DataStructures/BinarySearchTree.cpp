#include<bits/stdc++.h>
using namespace std;
FILE *in = fopen("basic","r");
//FILE *out =fopen("output","w");
struct node{
    struct node *left;
    int data;
    struct node *right;
};

node *newnode(int data)
{
    node *itr=(node *)calloc(1,sizeof(node));
    itr->left = itr->right = NULL;
    itr-> data=data;
    return itr;
}

node *binary_tree(node *itr,int data)
{
    if(itr==NULL)
        return newnode(data);
    if(itr->data>data)
        itr->left=binary_tree(itr->left,data);
    else
        itr->right=binary_tree(itr->right,data);
    return itr;
}

void postorder(node *itr)
{
    if(itr!=NULL)
    {
        postorder(itr->left);
        postorder(itr->right);
        fprintf(stdout,"%d\n",itr->data);
    }
}

void preorder(node *itr)
{
    if(itr!=NULL)
    {
        fprintf(stdout,"%d\n",itr->data);
        preorder(itr->left);
        preorder(itr->right);
    }
}
void inorder(node *itr)
{
    if(itr!=NULL)
    {
        inorder(itr->left);
        fprintf(stdout,"%d\n",itr->data);
        inorder(itr->right);
    }
}

int size(node *itr)
{
    if(itr==NULL)
        return 0;
    else
        return size(itr->left)+1+size(itr->right) ;

}
int maxDepth(node *itr)
{
    if(itr==NULL)
        return 0;
   else{ int ldepth=maxDepth(itr->left);
    int rdepth=maxDepth(itr->right);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;
}}
int minimumValue(node *itr)
{
    if(itr->left==NULL)
        return itr->data;
    return minimumValue(itr->left);
}

int search(node *itr,int data)
{
    if(itr==NULL)
        return 0 ;
    if(itr->data==data)
        return 1;
    if(itr->data>data)
        return search(itr->left,data);
    if(itr->data<data)
        return search(itr->right,data);
}

int main()
{

    
    int n,data;
    node *root;
    fscanf(in,"%d",&n);
    fscanf(in,"%d",&data);
    root=newnode(data);
   while(--n)
    {
        fscanf(in,"%d",&data);
        root=binary_tree(root,data);
    }
    fprintf(stdout,"In order Traversal:\n");
    inorder(root);
    fprintf(stdout,"Pre order Traversal:");
    preorder(root);
    fprintf(stdout,"Post order Traversal:");
    postorder(root);
    fprintf(stdout,"SIZE: %d Depth:%d ",size(root),maxDepth(root));
    cout << (float)clock()/CLOCKS_PER_SEC;
    /*cout << "what you want to find : ";
    cin >> data;
   cout << search(root,data);*/
}
