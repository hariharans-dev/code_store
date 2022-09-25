#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    char data;
    struct node *next;
}*head,*tail,*temp,*cnode,*head1,*tail1,*temp1,*head2,*tail2;
int n;
void creation(int c)
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->next=NULL;
    tail=cnode;
    head=cnode;
    cout<<"Enter the number of nodes: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        char item;cout<<"Enter the item: ";cin>>item;
        if(i==0)
            tail->data=item;
        else
        {
            cnode=(struct node*)malloc(sizeof(struct node));
            cnode->next=NULL;
            cnode->data=item;
            tail->next=cnode;
            tail=cnode;
        }
    }
    if(c==1)
    {
        tail1=tail;
        head1=head;
    }
    else
    {
        tail2=tail;
        head2=head;
    }
}
void reverse()
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->next=NULL;
    head1=cnode;
    tail1=cnode;
    for(int i=n;i>0;i--)
    {
        temp=head;
        for(int j=1;j<i;j++)
            temp=temp->next;
        if(i==n)
            tail1->data=temp->data;
        else
        {
            cnode=(struct node*)malloc(sizeof(struct node));
            cnode->next=NULL;
            cnode->data=temp->data;
            tail1->next=cnode;
            tail1=cnode;
        }
    }
}
int palindrome()
{
    temp=head;
    temp1=tail;int i=n;
    while(temp!=NULL)
    {
        if(temp->data!=temp1->data)
            return 0;
        temp1=head;
        for(int j=2;j<i;j++)
            temp1=temp1->next;
        i--;
        temp=temp->next;
    }
    return 1;
}
void display(int c)
{
    if(c==1)
        temp=head1;
    else
        temp=head2;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void index_merging()
{
    int pos;
    temp=head1;
    cout<<"Enter the position: ";cin>>pos;
    for(int i=0;i<pos;i++)
        temp=temp->next;
    temp1=temp->next;
    temp->next=head2;
    tail2->next=temp1;
}
int main()
{
    creation(1);
    creation(2);
    index_merging();
    display(1);
    getch();
    return 0;
}