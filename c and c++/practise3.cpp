#include <iostream>
#include <conio.h>
#include<string.h>
using namespace std;
int top=-1;
struct node
{
	char data;
	struct node *next;
}*cnode,*t;
int push(char c)
{
	if(top==-1)
	{
		cnode=(struct node*)malloc(sizeof(struct node));
		cnode->next=NULL;
		top++;
		cnode->data=c;
		t=cnode;
	}
	else
	{
		cnode=(struct node*)malloc(sizeof(struct node));
		cnode->next=NULL;
		cnode->data=c;
		t->next=cnode;
	}
}
char pop()
{
	char e=st.s[st.top];
	st.top--;
	return e;
}
