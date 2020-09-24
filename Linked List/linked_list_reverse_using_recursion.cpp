#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
using namespace std;


struct node{

	struct node*next;
	int data;
};

void insert(struct node** root,int data,struct node ** temp)
{

struct node* newnode= new struct node;
newnode->data=data;
newnode->next=NULL;
if((*root)==NULL)
{
*root=*temp=newnode;
}
else
{
	(*temp)->next=newnode;
	(*temp)=newnode;

}


}
void print(struct node*t)
{
	if(t==NULL)
		return;
		cout<<t->data<<" ";
	print(t->next);

}

void reverse(struct node **root,struct node*t)
{
if(t->next==NULL)
{
(*root)=t;
return;
}
reverse(root,t->next);

struct node*temp=t->next;
temp->next=t;
t->next=NULL;


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);

struct node* root,*temp;
root=NULL;
temp=NULL;

insert(&root,1,&temp);
insert(&root,2,&temp);
insert(&root,3,&temp);
insert(&root,4,&temp);
insert(&root,5,&temp);
struct node*t=root;

reverse(&root,t);
print(root);



	return 0;
}