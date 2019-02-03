#include<stdio.h>
#include<stdlib.h>

FILE *in = fopen("basic","r");


struct node{
	int data;
	node *left;
	node *right;
	int height;
};

int max(int a,int b)
{
	return (a>b) ? a : b;
}
node *new_node(int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->height=1;
	tmp->left=tmp->right=NULL;
	tmp->data=data;
	return tmp;
}

int height(node *tmp)
{
	if(tmp==NULL)
		return 0;
	return tmp->height;
}

int bf(node *tmp)
{
	if(tmp==NULL)
		return 0;
	return height(tmp->left)-height(tmp->right);
}

node *lr(node *x)
{
	node *z = x->right;
	node *A = z->left;

	z->left = x;
	x->right = A;

	x->height = max(height(x->left),height(x->right)) + 1;
	z->height = max(height(z->left),height(z->right)) + 1;

	return z;
}

node *rr(node *x)
{
	node *y = x->left;
	node *B = y->right;

	y->right = x;
	x->left = B;

	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}

node *insert(node *tmp,int data)
{
	if(tmp==NULL)
		return new_node(data);
	else if(tmp->data > data)
		tmp->left = insert(tmp->left,data);
	else if(tmp->data < data)
		tmp->right = insert(tmp->right,data);
	else
		return tmp;

	tmp->height = max(height(tmp->left),height(tmp->right)) + 1;

	int bal = bf(tmp);

	if(bal>1 && tmp->left->data > data)
		return rr(tmp);
	else if(bal>1 && tmp->left->data < data)
	{
		tmp->left = lr(tmp->left);
		return rr(tmp);
	}
	else if(bal<-1 && tmp->right->data < data)
		return lr(tmp);
	else if(bal<-1 && tmp->right->data > data)
	{
		tmp->right=rr(tmp->right);
		return lr(tmp);
	}

	return tmp;
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main()
{
	int n=0;
	node *root = NULL;
	fscanf(in,"%d",&n);
	while(n--)
	{
		int d;
		fscanf(in,"%d",&d);
		root=insert(root,d);
	}
	inorder(root);
	return 0;
}
