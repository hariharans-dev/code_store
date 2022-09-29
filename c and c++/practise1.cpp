#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left,*right;
}*root,*cnode,*temp;
struct node *newnode(int data)
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->data=data;
    cnode->left=NULL;
    cnode->right=NULL;
    return cnode;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->right);
        postorder(root->left);
        printf("%d\t",root->data);
    }
}
void leftskew()
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->left=NULL;
    root=cnode;
    temp=root;
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int item;scanf("%d",&item);
        if(i==0)
            temp->data=item;
        else
        {
            cnode=newnode(item);
            temp->left=cnode;
        }
    }
}
//inorder LDR
//preorder DLR
//postorder LRD
int main()
{
    
    return 0;
}