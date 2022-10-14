#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
	    int a,b,x,y;
	    cin>>a>>b>>x>>y;
	    float t1=a/x,t2=b/y;
        if(t1==t2)
            cout<<"Both"<<endl;
        else if(t1>t2)
            cout<<"Chef"<<endl;
        else 
            cout<<"Chefina"<<endl;
	}
    getch();
	return 0;
}