#include<iostream>
#include<conio.h>
using namespace std;
void display(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int a[]={100,22,33,44,35,90,88,77,101,99};int size=10;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i],k;
                for(k=i;k<size;k++)
                    a[k]=a[k-1];
                a[k]=temp;
                break;
            }   
        }
    }
    display(a,size);
    getch();
    return 0;
}