#include <iostream>
#include <conio.h>
#include<string.h>
using namespace std;
struct stack
{
	char s[20];
	int top;
	stack()
	{
		top=-1;
	}
}st;
int push(char c)
{
	st.s[++st.top] = c;
}
char pop()
{
	char e=st.s[st.top];
	st.top--;
	return e;
}
int main() 
{
	int n;cin>>n;
	while(n>=0)
	{
		string s;
		getline(cin,s);
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s[i]!=' ')
				push(s[i]);
			else 
			{
				while(st.top!=-1)
					cout<<pop();
				cout<<" ";
			}
		}
		while(st.top!=-1)
			cout<<pop();
		n--;
	}
    getch();
	return 0;
}