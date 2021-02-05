#include<stdio.h>
#include<stdlib.h>
struct nodet{
int ele;
struct nodet *left;
struct nodet *right;
};
struct que{
struct nodet *a[20];
int f;
int r;
};
struct nodet* insert(struct nodet *root,int ele);
struct que enqueu(struct que q, struct nodet *ele);
int isempty(struct que *q);
struct nodet* dequeu(struct que *q);
void print(struct nodet *root);
void find(struct nodet *root);
void count(struct nodet *root);
struct nodet* findd(struct nodet *root,int ele);
struct nodet* findparent(struct nodet* root,struct nodet* temp);
struct nodet* findlast(struct nodet* root);
struct nodet* del(struct nodet *root,int ele);
void preorder(struct nodet *root);
void inorder(struct nodet *root);
void postorder(struct nodet *root);
void main()
{
	struct nodet *root=NULL;
printf("enter 1 to insert\nenter 2 to print the structure\n enter 3 to find the element\n enter 4 to know the count of elements\n enter 5 to delete particularelement\n6 for preorder\n7 for postorder\n8 for inorder\n");
	int opt,ele;
	do{
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			printf("enter the elemetn to insert");
			scanf("%d",&ele);
			root=insert(root,ele);
			break;
		case 2:
			print(root);
			break;
		case 3:
			find(root);
			break;
		case 4:
			count(root);
			break;
		case 5:
			printf("enter the element to delete");
			scanf("%d",&ele);
			root=del(root,ele);
			break;
		case 6:
			preorder(root);
			break;
		case 7:
			postorder(root);
			break;
		case 8:
			inorder(root);
			break;
		default:
			printf("program is termitted\n");
}			
}while(opt!=9);
}

//INSERTING ELEMENTS INTO THE TREE STRUCTURE

struct nodet* insert(struct nodet *root,int ele)
{
	if(root==NULL)
	{
		root=(struct nodet*)malloc(sizeof(struct nodet));
		root->ele=ele;
		root->left=NULL;
		root->right=NULL;
	}
    else
    {
        struct nodet * temp, *temp1;
        temp=(struct nodet *)malloc(sizeof(struct nodet));
        temp->ele=ele;
        temp->left=NULL;
        temp->right=NULL;
        struct que q;
        q.r=-1;
        q.f=-1;
        q=enqueu(q,root);
        while(!isempty(&q))
        {
            temp1=dequeu(&q);
            if(temp1->left!=NULL)
            {
                q=enqueu(q,temp1->left);
            }
            else
            {
                temp1->left=temp;        
                break;
            }
            if(temp1->right!=NULL)
            {
                q=enqueu(q,temp1->right);
            }
            else
            {
                temp1->right=temp;
                break;
            }
                
        }
    }
    return root;
}

struct que enqueu(struct que q, struct nodet *ele)
{
    q.r++;
    q.a[q.r]=ele;
    return q;
}
int isempty(struct que *q)
{
    if(q->f==q->r)
        return 1;
    else
        return 0;
}
struct nodet* dequeu(struct que *q)
{
    if(q->f==q->r)
        return NULL;
    else
    {
            q->f++;
            return q->a[q->f];
    }
}

//PRINTING THE TREE STRUCTURE


void print(struct nodet *root)
{
	struct nodet *temp;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
	{
		temp=dequeu(&q);
		printf("%d",temp->ele);
		if(temp->left!=NULL)
			q=enqueu(q,temp->left);
		if(temp->right!=NULL)
			q=enqueu(q,temp->right);
	}
}

//FINDING THE PRESENCE IF ELEMENT IN THE TREE


void find(struct nodet *root)
{
	int f=0;
	int find;
	printf("enter the element to find");
	scanf("%d",&find);
	if(root==NULL)
	printf("no elements present to find\n");
else{
	struct nodet* temp;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
{
		temp=dequeu(&q);
		if(temp->ele==find){
			f=1;
			break;
}
		if(temp->left!=NULL)
			q=enqueu(q,temp->left);
		if(temp->right!=NULL)
			q=enqueu(q,temp->right);
}
if(f==1)
printf("element found\n");
else
printf("element not found\n");
}
}

//GETTING THE COUNT OF ELEMENTS IN THE BINARY TREE STRUCTURE


void count(struct nodet *root)
{
	int c=1;
	if(root==NULL)
	printf("th no.elements are 0\n");
	else{
	struct nodet *temp;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
{
		temp=dequeu(&q);
		if(temp->left!=NULL)
		{
			q=enqueu(q,temp->left);
			c=c+1;
		}
		if(temp->right!=NULL)
		{
			q=enqueu(q,temp->right);
			c=c+1;
		}
}
printf("the no.of elements is%d\n",c);
}}
struct nodet* findd(struct nodet *root,int k)
{	int f=0;
	struct nodet* temp;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
{
		temp=dequeu(&q);
		if(temp->ele==k){
			f=1;
			break;
}
		if(temp->left!=NULL)
			q=enqueu(q,temp->left);
		if(temp->right!=NULL)
			q=enqueu(q,temp->right);
}
if(f==1)
return(temp);
else
return (0);
}
struct nodet* findparent(struct nodet* root,struct nodet* temp)
{
	struct nodet *temp1;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
{
	temp1=dequeu(&q);
	if(temp1->left==temp)
	{
		return(temp1);
	}
	else
	{
		if(temp1->left!=NULL)
			q=enqueu(q,temp1->left);
	}
	if(temp1->right==temp)
		return(temp1);
	else
{
	if(temp1->right!=NULL)
		q=enqueu(q,temp1->right);
}
}
return NULL;
}
struct nodet* findlast(struct nodet* root)
{
	
	struct nodet *temp;
	struct que q;
	q.f=-1;
	q.r=-1;
	q=enqueu(q,root);
	while(!isempty(&q))
	{
		temp=dequeu(&q);
		if(temp->left!=NULL)
			q=enqueu(q,temp->left);
		if(temp->right!=NULL)
			q=enqueu(q,temp->right);
	}
return temp;
}

// DELETION OF PARTICULAR ELEMENT


struct nodet* del(struct nodet *root,int ele)
{
	struct nodet *temp;
	struct nodet *temp1;
	struct nodet *temp2;
	temp=findd(root,ele);
	if(temp!=NULL)
	{
		temp1=findlast(root);
		temp2=findparent(root,temp1);
		
		temp->ele=temp1->ele;
		if(temp2->left==temp1)
			temp2->left==NULL;
		else
			temp2->right==NULL;
	}
}

//PREORDER TRANSVERSAL

void preorder(struct nodet *root)
{	struct nodet *temp;
	if(root!=NULL)
	{
		printf("%d",root->ele);
		preorder(root->left);
		preorder(root->right);
	}
}

//POSTORDER TRANSVERSAL

void postorder(struct nodet *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d",root->ele);
	}
}

//INORDER TRANSVERSAL


void inorder(struct nodet *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->ele);
		inorder(root->right);
	}
}//B172193
	
                                                              //B172193	
