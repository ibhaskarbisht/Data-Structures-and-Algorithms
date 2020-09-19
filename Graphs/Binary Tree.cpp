#include<bits/stdc++.h>
using namespace std;

struct node{
struct node*left,*right;
int info;
};

struct node* newnode(int info)
{
struct node*temp=new struct node();
temp->info=info;
temp->left=NULL;
temp->right=NULL;
return temp;

}

void inorder(struct node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->info<<" ";
		inorder(root->right);
	}

}

struct node* insert(struct node*root,int info)
{
if(root==NULL)
	return newnode(info);
else if(info>(root)->info)
	(root)->right=insert((root)->right,info);

else if(info<(root)->info)
	(root)->left=insert((root)->left,info);


}


int smallest(struct node*root)
{

if(root->left==NULL&&root->right==NULL)
return root->info;
smallest(root->left);

}

int largest(struct node*root)
{
if(root->left==NULL&&root->right==NULL)
	return root->info;
largest(root->right);

}



int lheight(struct node*root)
{

static int count=0;
if(root==NULL)
return count;

lheight(root->left);
count++;
}


int rheight(struct node*root)
{

static int count=0;
if(root==NULL)
return count;

rheight(root->right);
count++;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
	
	struct node*root=NULL;
	root=insert(root,5);
	insert(root,3);
	insert(root,2);
	insert(root,6);
	insert(root,8);

cout<<"Smallest element is->"<<
	return 0;
}