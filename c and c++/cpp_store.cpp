//1. stack implementation

#include<iostream>
using namespace std;
int size=10;
struct stack
{
	int a[10];
	int top;
	stack()
	{
		top=-1;
	}
}s;
int isfull()
{
	if(s.top==size-1)
		return 1;
	return 0;
}
int isempty()
{
	if(s.top==-1)
		return 1;
	return 0;
}
void push()
{
	if(isfull()==1)
		cout<<"The stack is full"<<endl;
	else
	{
		int item;
		cout<<"Enter the item: ";cin>>item;
		s.a[++s.top]=item;
	}
}
void display()
{
	for(int i=s.top;i>=0;i--)
		cout<<s.a[i]<<" ";
	cout<<endl;
}
int pop()
{
	if(isempty()==1)
		cout<<"The stack is empty"<<endl;
	else
	{
		int item;
		item=s.a[s.top];
		s.top--;
	}
}
int main()
{
	int c;
	do
	{
		cout<<"Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\nEnter 4 for exit"<<endl;
		cout<<"Enter: ";cin>>c;
		switch(c)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	} while ((c==1)||(c==2)||(c==3));
}

//2. infix to postfix

#include <iostream>
using namespace std;
struct stack
{
    int arr[100];
    int top;
    stack()
    {
        top=-1;
    }
} s;

void push(char x)
{
    s.arr[++s.top] = x;
}

char pop()
{
    return s.arr[s.top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '/' || x == '*')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}
int main()
{
    string postfix, infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (s.top != -1 && s.arr[s.top] != '(')
            {
                postfix += pop();
            }
            pop();
        }

        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            postfix += c;
        }

        else
        {
            while (s.top != -1 && precedence(s.arr[s.top]) >= precedence(c))
            {
                postfix += pop();
            }
            push(c);
        }
    }
    while (s.top != -1)
    {
        postfix += pop();
    }
    cout << "The postfix:  " << postfix;
}

//3. infix to prefix

#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
struct stack
{
    int arr[100];
    int top;
} st;
void push(char x)
{
    st.arr[++st.top] = x;
}
char pop()
{
    return st.arr[st.top--];
}
int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '/' || x == '*')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}
int main()
{
    st.top = -1;
    string prefix, infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (c == ')')
        {
            push(c);
        }
        else if (c == '(')
        {
            while (st.top != -1 && st.arr[st.top] != ')')
            {
                prefix += pop();
            }
            pop();
        }

        else if (c >= 'a' && c <= 'z')
        {
            prefix += c;
        }

        else
        {
            while (st.top != -1 && precedence(st.arr[st.top]) >= precedence(c))
            {
                prefix += pop();
            }
            push(c);
        }
    }
    while (st.top != -1)
    {
        prefix += pop();
    }
    reverse(prefix.begin(), prefix.end());
    cout << "The prefix: " << prefix;
}

//4. postfix evaluation

#include<iostream>
using namespace std;
struct stack
{
	int a[20],top;
	stack()
	{
		top=-1;
	}
}s;
void push(int e)
{
	s.a[++s.top]=e;
}
int pop()
{
	int e=s.a[s.top];
	s.top--;
	return e;
}
int main()
{
	string k;
	cout<<"Enter the postfix expression: ";cin>>k;
	for(int i=0;k[i]!='\0';i++)
	{
		char c=k[i];
		if(isdigit(c))
			push(int(c-48));
		else
		{
			int p1=pop();
			int p2=pop();
			if(c=='+')
				push(p2+p1);
			else if(c=='-')
				push(p2-p1);
			else if(c=='*')
				push(p2*p1);
			else if(c=='/')
				push(p2/p1);
		}
	}
	cout<<s.a[s.top];
	return 0;
}

//5. prefix evalution

#include<iostream>
using namespace std;
struct stack
{
	int a[20],top;
	stack()
	{
		top=-1;
	}
}s;
void push(int e)
{
	s.a[++s.top]=e;
}
int pop()
{
	int e=s.a[s.top];
	s.top--;
	return e;
}
int main()
{
	string s;
	cout<<"Enter the postfix expression: ";cin>>s;
	for(int i=s.length()-1;i>=0;i--)
	{
		char c=s[i];
		if(isdigit(c))
			push(int(c-48));
		else
		{
			int p1=pop();
			int p2=pop();
			switch(c)
			{
				case '+':
				push(p1+p2);
				break;
				case '-':
				push(p1-p2);
				break;
				case '*':
				push(p1*p2);
				break;
				case '/':
				push(p1/p2);
				break;
			}
		}
	}
	cout<<pop();
	return 0;
}

//6. queue implementation

#include<iostream>
using namespace std;
struct queue
{
	int a[20],front,rear;
	queue()
	{
		front=rear=-1;
	}
}q;
void insertion()
{
	if(q.rear==9)
		cout<<"queue is full"<<endl;
	else
	{
		int item;cout<<"Enter item: ";cin>>item;
		if(q.rear==-1)
			q.front=q.rear=0;
		else
			q.rear++;
		q.a[q.rear]=item;
	}
}
void deletion()
{
	if(q.rear==-1)
		cout<<"The queue is empty"<<endl;
	else
	{
		if(q.rear==0)
			q.front=q.rear=-1;
		else
			q.front++;
	}
}
void display()
{
	for(int i=q.front;i<=q.rear;i++)
		cout<<q.a[i]<<" ";
	cout<<endl;
}
int main()
{
	int c;
	do
	{
		cout<<"1 for insertioin\n2 for deletion\n3 for display\n4 for exit\n";cin>>c;cout<<"Enter: ";
		switch(c)
		{
			case 1:
			insertion();
			break;
			case 2:
			deletion();
			break;
			case 3:
			display();
			break;
		}
	} while ((c==1)||(c==2)||(c==3));
}

//7. circular queue

#include<iostream>
using namespace std;
int size=10;
struct queue
{
	int a[10],fr,re;
	queue()
	{
		fr=re=-1;
	}
}q;
void insertion()
{
	if((q.re+1)%size==q.fr)
		cout<<"queue is full"<<endl;
	else
	{
		int item;
		cout<<"Enter item: ";cin>>item;
		if(q.fr==-1)
			q.fr=0;
		q.re=(q.re+1)%size;
		q.a[q.re]=item;
	}
}
void deletion()
{
	if(q.re==-1)
		cout<<"queue is empty"<<endl;
	else
	{
		if(q.re==q.fr)
			q.fr=q.re=-1;
		else
			q.fr=(q.fr+1)%size;
	}
}
void display()
{
	for(int i=q.fr;i<=q.re;i++)
		cout<<q.a[i]<<" ";
	cout<<endl;
}
int main()
{
	int c;
	do
	{
		cout<<"1 for insertion\n2 for deletion\n3 for display\n4 for exit"<<endl;
		cout<<"Enter: ";cin>>c;
		switch(c)
		{
			case 1:
			insertion();
			break;
			case 2:
			deletion();
			break;
			case 3:
			display();
			break;
		}
	} while ((c==1)||(c==2)||(c==3));	
}

//8. conditional queue

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
struct item
{
    int value;
    int priority;
};
item pr[100000];
int size = 0;
void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}
int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;
    for (int i = 0; i <= size; i++)
    {
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}
void dequeue()
{
    int ind = peek();
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }
    size--;
}
int main()
{
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
    int ind = peek();
    cout << pr[ind].value << endl;
    dequeue();
    ind = peek();
    cout << pr[ind].value << endl;
    dequeue();
    ind = peek();
    cout << pr[ind].value << endl;
    getch();
    return 0;
}

//9. double ended queue

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
int MAX = 100;
#define MAX 100
int deque[MAX];
int f = -1, r = -1;
void insert_front()
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        f = MAX - 1;
        deque[f] = x;
    }
    else
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        f = f - 1;
        deque[f] = x;
    }
}
void insert_rear()
{
    if ((f == 0 && r == MAX - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        r = 0;
        deque[r] = x;
    }
    else if (r == MAX - 1)
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        r = 0;
        deque[r] = x;
    }
    else
    {
        int x;
        cout << "Enter the element to be inserted: ";
        cin >> x;
        r++;
        deque[r] = x;
    }
}
void display()
{
    int i = f;
    printf("\nElements in a deque are: ");

    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d", deque[r]);
}
void getfront()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at front is: %d", deque[f]);
    }
}
void getrear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at rear is %d", deque[r]);
    }
}
void delete_front()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else if (f == (MAX - 1))
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = f + 1;
    }
}
void delete_rear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = MAX - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = r - 1;
    }
}

int main()
{
    int choice;
    cout << "1. Enqueue Front" << endl;
    cout << "2. Dequeue Front" << endl;
    cout << "3. Enqueue Rear" << endl;
    cout << "4. Dequeue Rear" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert_front();
        break;
    case 2:
        delete_front();
        break;
    case 3:
        insert_rear();
        break;
    case 4:
        delete_rear();
        break;
    case 5:
        display();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid choice" << endl;
    }
    while (choice > 0 && choice <= 6);
    return 0;
}

//10. Linked list

#include<iostream>
using namespace std;
int n;
struct node
{
	int data;
	struct node *next;
}*head,*tail,*cnode,*temp,*temp2;
void creation()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	head=cnode;
	tail=cnode;
	cout<<"Enter the number of nodes: ";cin>>n;
	for(int i=0;i<n;i++)
	{
		int item;cout<<"Enter the item: ";cin>>item;
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
}
void insertion()
{
	int pos,item;cout<<"Enter the position and item: ";cin>>pos>>item;
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->data=item;
	cnode->next=NULL;
	if(pos==0)
	{
		cnode->next=head;
		head=cnode;
	}
	else if(pos==(n-1))
	{
		tail->next=cnode;
		tail=cnode;
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
		cnode=(struct node*)malloc(sizeof(struct node));
		cnode->data=item;
		cnode->next=temp->next;
		temp->next=cnode;
	}
	n++;
}
void deletion()
{
	int pos;cout<<"Enter the position: ";cin>>pos;
	if(pos==0)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	else if(pos==(n-1))
	{
		temp2=tail;
		temp=head;
		while(temp->next->next==NULL)
			temp=temp->next;
		temp->next=NULL;
		free(temp2);
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
		temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
	}
}
void display()
{
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
	int c;
	do
	{
		cout<<"1 for creation\n2 for insertion\n3 for deletion\n4 for display\n5 for exit"<<endl;
		cout<<"Enter: ";cin>>c;
		switch(c)
		{
			case 1:
			creation();
			break;
			case 2:
			insertion();
			break;
			case 3:
			deletion();
			break;
			case 4:
			display();
			break;
		}
	} while ((c==1)||(c==2)||(c==3)||(c==4));
	
}

//11. Doubly linked list

#include<iostream>
using namespace std;
int n;
struct node
{
	int data;
	struct node *next,*prev;
}*head,*tail,*cnode,*temp;
void creation()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	cnode->prev=NULL;
	head=cnode;
	tail=cnode;
	cout<<"Enter the number of node: ";cin>>n;
	for(int i=0;i<n;i++)
	{
		int item;cout<<"Enter item: ";cin>>item;
		if(i==0)
			tail->data=item;
		else
		{
			cnode=(struct node*)malloc(sizeof(struct node));
			cnode->next=NULL;
			cnode->data=item;
			cnode->prev=tail;
			tail->next=cnode;
			tail=cnode;
		}
	}
}
void insertion()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->prev=NULL;
	cnode->next=NULL;
	int item,pos;cout<<"Enter position and item: ";cin>>pos>>item;
	cnode->data=item;
	if(pos==0)
	{
		cnode->next=head;
		head->prev=cnode;
		head=cnode;
	}
	else if(pos==(n-1))
	{
		cnode->prev=tail;
		tail->next=cnode;
		tail=cnode;
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
		cnode->next=temp->next;
		cnode->prev=temp;
		temp->next=cnode;
		temp=cnode->next;
		temp->prev=cnode;
	}
}
void deletion()
{
	int pos;cout<<"Enter the position: ";cin>>pos;
	if(pos==0)
	{
		temp=head;
		temp->next=NULL;
		free(temp);
		head=head->next;
		head->prev=NULL;
	}
	else if(pos==(n-1))
	{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		temp->prev=NULL;
		free(temp);
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
		temp->next->prev=temp;
		temp->next=temp->next->next;
	}
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	creation();
	insertion();
	deletion();
	display();
	return 0;
}

//12. stack implementation using linked list

#include<iostream>
using namespace std;
int n=-1,e;
struct node
{
	int data;
	struct node *next;
}*top,*cnode,*temp;
void push()
{
	int item;cout<<"Enter the item: ";cin>>item;
	if(n==-1)
		top->data=item;
	else
	{
		cnode=(struct node*)malloc(sizeof(struct node));
		cnode->data=item;
		cnode->next=top;
		top=cnode;
	}
	n++;
}
void pop()
{
	if(n==-1)
		cout<<"The stack is empty"<<endl;
	else
		top=top->next;
	n--;
}
void display()
{
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	top=cnode;
	int c;
	do
	{
		cout<<"1 for push\n2 for pop\n3 for display\n4 for exit"<<endl;
		cout<<"Enter: ";cin>>c;
		switch(c)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	} while ((c==1)||(c==2)||(c==3));
	return 0;
}

//13. queue implementation using linked list

#include<iostream>
using namespace std;
int n=0;
struct node
{
	int data;
	struct node *next;
}*head,*tail,*temp,*cnode;
void insertion()
{
	int item;cout<<"Enter item: ";cin>>item;
	if((n==0)&&(tail->next==NULL))
		tail->data=item;
	else
	{
		cnode=(struct node*)malloc(sizeof(struct node));
		cnode->next=NULL;
		cnode->data=item;
		tail->next=cnode;
		tail=cnode;
	}
	n++;
}
void deletion()
{
	if(n==1)
		;
	else
		head=head->next;
	n--;
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		if(n==0)
			break;
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main()
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	head=cnode;
	tail=cnode;
	int c;
	do
	{
		cout<<"1 for insertion\n2 for deletion\n3 for display\n4 for exit"<<endl;
		cout<<"Enter: ";cin>>c;
		switch(c)
		{
			case 1:
			insertion();
			break;
			case 2:
			deletion();
			break;
			case 3:
			display();
			break;
		}
	} while ((c==1)||(c==2)||(c==3));
	return 0;
}

//14. polynomial addition

#include<iostream>
using namespace std;
int n=0;
struct node
{
	int data,pow;
	struct node *next;
}*head,*tail,*head1,*head2,*tail1,*tail2,*cnode,*temp,*temp2;
void creation(int c)
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	head=cnode;
	tail=cnode;
	int n1;
	cout<<"Enter the number of nodes: ";cin>>n1;
	if(c==1)
		n=n1;
	for(int i=0;i<n1;i++)
	{
		int item,pos;cout<<"Enter coefficient and power: ";cin>>item>>pos;
		if(i==0)
		{
			tail->data=item;
			tail->pow=pos;
		}
		else
		{
			cnode=(struct node*)malloc(sizeof(struct node));
			cnode->data=item;
			cnode->pow=pos;
			cnode->next=NULL;
			tail->next=cnode;
			tail=cnode;
		}
	}
	if(c==1)
	{
		head1=head;
		tail1=tail;
	}
	else
	{
		head2=head;
		tail2=tail;
	}
}
void addition()
{
	temp2=head2;
	while(temp2!=NULL)
	{
		temp=head1;
		int present=0;
		while(temp!=NULL)
		{
			if(temp2->pow==temp->pow)
			{
				temp->data+=temp2->data;
				present=1;
			}
			temp=temp->next;
		}
		if(present==0)
		{
			cnode=(struct node*)malloc(sizeof(struct node));
			cnode->data=temp2->data;
			cnode->pow=temp2->pow;
			cnode->next=NULL;
			tail1->next=cnode;
			tail1=cnode;
			n++;
		}
		temp2=temp2->next;
	}
}
void sorting()
{
	temp=head1;
	while(temp!=NULL)
	{
		temp2=temp->next;
		while(temp2!=NULL)
		{	
			if(temp->pow<temp2->pow)
			{
				int temph=temp->data;
				temp->data=temp2->data;
				temp2->data=temph;
				int pos=temp->pow;
				temp->pow=temp2->pow;
				temp2->pow=pos;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
}
void display(int c)
{
	if(c==1)
		temp=head1;
	else
		temp=head2;
	for(int i=n;i>0;i--)
	{
		if(i==1)
			cout<<temp->data<<"x^"<<temp->pow<<endl;
		else
			cout<<temp->data<<"x^"<<temp->pow<<" + ";
		temp=temp->next;
	}
}
int main()
{
	creation(1);
	creation(2);
	addition();
	sorting();
	display(1);
}


