#include<iostream>
#include<conio.h>
using namespace std;
struct stack
{
    char a[20];
    int top;
    stack()
    {
        top=-1;
    }
}st;
char pop()
{
    char e=st.a[st.top];
    return e;
}
void push(char e)
{
    st.a[++st.top]=e;
}
int main()
{
    int n;cin>>n;
    while(n>0)
    {
        string s;cin>>s;int count=0;
        for(int i=0;s[i]!='\0';i++)
            count++;
        for(int i=count-1;i>=0;i--)
        {
            if(s[i]!=' ')
                push(s[i]);
            else
            {
                if(st.top!=-1)
                    cout<<pop();
                cout<<" ";
            }
        }
        cout<<count<<endl;
        n--;
    }
    getch();
    return 0;
}