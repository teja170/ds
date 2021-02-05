#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node *left;
	struct node *right;
};
struct node* insert(struct node *root);
struct node* search(struct node *root,int ele);
struct node* del(struct node *root,int ele);
void main()
{
	int opt;int ele;int k;
	struct node *root=NULL;
	printf("enter 1 to insert\n enter 2 to search for the element\n enter 3 to delete the element\nenter 5 to exit\n");
	do{
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt){
			case 1:
				root=insert(root);
				break;
			case 2:
				printf("enter the element to search");
				scanf("%d",&ele);
				root=search(root,ele);;
				break;
			case 3:	
				printf("enter the element to delete");
				scanf("%d",&ele);
				root=del(root,ele);
				break;
			


				
	}
}while(opt!=5);
}
// INSERTION OF ELEMENTS INTO A BINARY TREE

struct node* insert(struct node *root)
{
	struct node *temp;
	struct node *n;
	temp=root;
	int ele;
	printf("enter the element to insert");
	scanf("%d",&ele);
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->e=ele;
		root->left=NULL;
		root->right=NULL;
	}	
	else{
	n=(struct node*)malloc(sizeof(struct node));
	n->left=NULL;n->right=NULL;
	while(1)
	{
		if(temp->e>n->e)
		{
			if(temp->left!=NULL)
				temp=temp->left;
			else{
				temp->left=n;
				break;
				}
		}
		else
		{
			if(temp->right!=NULL)
				temp=temp->right;
			else{
				temp->right=n;
				break;
				}
		}
	}
}
}

// SEARCHING FOR PARTICULAR ELEMENT IN BINARY TREE

struct node* search(struct node *root,int ele)
{
	struct node *temp;
	temp=root;
	int f=0;
	while(1)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		else if(temp->e>ele)
		{
			if(temp->left!=NULL)
				temp=temp->left;
			else
				break;
			if(temp->right!=NULL)
				temp=temp->right;
			else
				break;
		}
}
if(f==1)
{	printf("element found\n");
	return(temp);
}
else
	printf("element not found\n");
}

// DELETION OF ELEMENT FROM BINARY TREE

struct node* del(struct node *root,int ele)
{
	struct node *temp;
	struct node *temp1;struct node *parent;
	temp1=search(root,ele);
	parent=temp1;
	temp=temp1->right;
	while(temp->left!=NULL)
	{
		parent=temp;
		temp=temp->left;
	}
	temp1->e=temp->e;
	parent->left=temp->right;
	return(root);
}


