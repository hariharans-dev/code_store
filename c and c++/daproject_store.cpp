//question 1

#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;cin>>n;int count=1;
    while(count<=n)
    {
        int c;cin>>c;
        int n1;cin>>n1;int a[n1];
        for(int i=0;i<n1;i++)
        {
            cin>>a[i];
        }
        int s=0;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n1;j++)
            {
                if(a[i]==a[j])
                    continue;
                else
                {
                    if((a[i]+a[j])==c)
                    {
                        s=1;
                        cout<<"Case #"<<count<<": "<<i+1<<" "<<j+1<<endl;
                        break;
                    }
                }
            }
            if(s==1)
                break;
        }
        count++;
    }
    getch();
    return 0;
}

//question 2

#include <iostream>
#include <conio.h>
using namespace std;
int t=-1;
struct node
{
	char data;
	struct node *next;
}*cnode,*top,*temp;
void push(char c)
{
	cnode=(struct node*)malloc(sizeof(struct node));
	cnode->next=NULL;
	cnode->data=c;
	if(t==-1)
		top=cnode;
	else
	{
		cnode->next=top;
		top=cnode;
	}
	t++;
}
char pop()
{
	char c;
	c=top->data;
	top=top->next;
	t--;
	return c;
}
int main() 
{
	int n;cout<<"Enter the number of input: ";cin>>n;
	while(n>0)
	{
		string s;
		getline(cin>>ws,s);
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i]!=' ')
				push(s[i]);
			else 
			{
				while(t!=-1)
					cout<<pop();
				cout<<" ";
			}
		}
		while(t!=-1)
			cout<<pop();
        cout<<endl;
		n--;
	}
    getch();
	return 0;
}

// question 3

#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int n;cin>>n;
	while(n>0)
	{
		int c;cin>>c;int a1[c],a2[c],min;
		for(int i=0;i<c;i++)
			cin>>a1[i];
		for(int i=0;i<c;i++)
			cin>>a2[i];
		for(int i=0;i<c-1;i++)
			for(int j=i;j<c;j++)
				if(a1[i]<a1[j])
				{
					int temp=a1[i];
					a1[i]=a1[j];
					a1[j]=temp;
				}
		for(int i=0;i<c-1;i++)
			for(int j=i;j<c;j++)
				if(a2[i]>a2[j])
				{
					int temp=a2[i];
					a2[i]=a2[j];
					a2[j]=temp;
				}
		for(int i=0;i<c;i++)
			min+=a1[i]*a2[i];
		cout<<min<<endl;
		n--;
	}
	getch();
	return 0;
}

// question 4







