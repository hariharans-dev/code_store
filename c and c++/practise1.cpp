#include<iostream>
#include<conio.h>
using namespace std;
int present,miin;
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
void insert(struct node *r,int item)
{
    if(item<=r->data)
    {
        if(r->left!=NULL)
            insert(r->left,item);
        else
            r->left=newnode(item);
    }
    else if(item>r->data)
    {
        if(r->right!=NULL)
            insert(r->right,item);
        else    
            r->right=newnode(item);
        
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
void creation()
{
    int n;cout<<"Enter the number of nodes: ";cin>>n;
    for (int i = 0; i < n; i++)
    {
        int item;cout<<"Enter item: ";cin>>item;
        if(i==0)
            root=newnode(item);
        else
            insert(root,item);
    }
}
void rec(struct node *r,int item)
{
    if((r!=NULL)&&(present!=1))
    {
        if(r->data==item)
            present=1;
        else if(item<r->data)
            rec(r->left,item);
        else
            rec(r->right,item);
    }
}
void search(int p=0,int item=0)
{
    if(p==0)
    {
        cout<<"Enter the searching element: ";cin>>item;
    }
    rec(root,item);
    if(present==1)
        cout<<"present"<<endl;
    else
        cout<<"not present"<<endl;
}
int find_min(struct node *r)
{
    if(r!=NULL)
    {
        find_min(r->left);
        if(r->data<miin)
            miin=r->data;
    }
    return miin;
}
int find_max(struct node *r)
{
    if(r!=NULL)
    {
        find_max(r->right);
        if(r->data>miin)
            miin=r->data;
    }
    return miin;
}
int main()
{
    creation();
    
    // miin=root->data;
    // cout<<find_max(root);
    // // inorder(root);
    // // search(1,6);

    getch();
    return 0;
}