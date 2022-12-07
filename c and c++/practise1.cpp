#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int data;
    struct node *next;
}*head,*tail,*cnode;
void creation()
{
    cnode=(struct node *)malloc(sizeof(struct node));
    cnode->next=NULL;
    head=tail=cnode;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int item;cin>>item;
        if(i==0)
            cnode->data=item;
        else
        {
            cnode=(struct node*)malloc(sizeof(struct node));
            cnode->next=NULL;
            cnode->data=item;
            tail->next=cnode;
            tail=cnode;
        }
    }
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    creation();
    display();
    getch();
    return 0;
}
