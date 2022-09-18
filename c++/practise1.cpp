#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next,*prev;
}*head,*tail,*temp,*cnode,*ohead,*otail,*ehead,*etail,*temp1,*cnode1;
void creation()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->prev=cnode->next=NULL;
	head=cnode;
	tail=cnode;
	int n;cout<<"Enter: ";cin>>n;
	for(int i=0;i<n;i++)
	{
		int item;cout<<"Enter: ";cin>>item;
		if(i==0)	
			tail->data=item;
		else
		{
			cnode=(struct node*)malloc(sizeof(struct node));
			cnode->next=NULL;
			cnode->data=item;
			tail->next=cnode;
			cnode->prev=tail;
			tail=cnode;
		}
	}
}
void partition()
{
	ohead=otail=cnode=(struct node*)malloc(sizeof(struct node));
	ehead=etail=cnode1=(struct node*)malloc(sizeof(struct node));
	otail->next=otail->prev=etail->next=etail->prev=NULL;
	temp=head;
	int o=0,e=0;
	while(temp!=NULL)
	{
		if(temp->data%2==0)
		{
			if(e==0)
				etail->data=temp->data;
			else
			{
				cnode=(struct node*)malloc(sizeof(struct node));
				cnode->next=NULL;
				cnode->data=temp->data;
				cnode->prev=etail;
				etail->next=cnode;
				etail=cnode;
			}
			e++;
		}
		else if(temp->data%2==1)
		{
			if(o==0)
				otail->data=temp->data;
			else
			{
				cnode=(struct node*)malloc(sizeof(struct node));
				cnode->next=NULL;
				cnode->prev=otail;
				cnode->data=temp->data;
				otail->next=cnode;
				otail=cnode;
			}
			o++;
		}
		temp=temp->next;
	}
}
void display(int c)
{
	if(c==0)
		temp=head;
	else if(c==1)
		temp=ohead;
	else
		temp=ehead;
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
	display(2);
}