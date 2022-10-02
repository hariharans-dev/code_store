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

