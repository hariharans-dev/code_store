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