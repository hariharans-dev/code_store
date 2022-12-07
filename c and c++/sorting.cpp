#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
}*root,*cnode;
struct node* newnode(int a)
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->data =a;
    cnode->left =NULL;
    cnode->right =NULL;
    return cnode;
}
void insert(struct node* root,int a)
{
    if(a<=root->data)
    {
        if(root->left!=NULL)
            insert(root->left,a);
        else
            root->left =newnode(a);
    }
    else
    {
        if(root->right!=NULL)
            insert(root->right,a);
        else
            root->right =newnode(a);
    }
}
void creation()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        if(i==0)
            root=newnode(a);
        else
            insert(root,a);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    creation();
    inorder(root);
    preorder(root);
    getch();
    return 0;
}