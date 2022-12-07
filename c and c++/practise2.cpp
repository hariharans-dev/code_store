#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root,*cnode;
struct node * newnode(int item)
{
    cnode=new node();
    cnode->left=NULL;
    cnode->right=NULL;
    cnode->data=item;
    return cnode;
}
void creation()
{
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
}
void preorder(struct node *r)
{
     if(r!=NULL)
     {
    	cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
} 
void inorder(struct node *r)
{
     if(r!=NULL)
     {
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}
void postorder(struct node *r)
{
    if(r!=NULL)
    {
    	postorder(r->left);
        postorder(r->right);
        cout<<r->data<<" ";
    }
} 

int main()
{
	creation();
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	getch();
	return 0;
}