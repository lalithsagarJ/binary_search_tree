#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *llink,*rlink;
};
struct node *getnode()
{
	struct node *x=(struct node *)malloc(sizeof(struct node));
	if(x==NULL)
		printf("\nno memory");
	else
		return x;
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->llink);
		printf("%d",root->data);
		inorder(root->rlink);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d",root->data);
	}
}
void insert(struct node *root,int item)
{
	struct node *temp=getnode();
	temp->data=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		struct node *preptr,*ptr=root;
		while(ptr!=NULL)
		{
			preptr=ptr;
			if(item<ptr->data)
				ptr=ptr->llink;
			else
				ptr=ptr->rlink;
		}
		if(item<preptr->data)
			preptr->llink=temp;
		else
			preptr->rlink=temp;
	}
}
void main()
{
	int n,ele;
	struct node *root=NULL;
	printf("\nhow many elements ?");
	scanf("%d",&n);	
	printf("\n\nenter the item:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ele);
		insert(root,ele);
	}
	printf("\n\nINORDER TRAVERSAL\n");
	inorder(root);
	printf("\n\nPREORDER TRAVERSAL\n");
	preorder(root);
	printf("\n\nPOSTORDER TRAVERSAL\n");
	postorder(root);
}
