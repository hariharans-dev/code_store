//1. selection sorting

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
        for(int j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    display(a,size);
    getch();
    return 0;
}

// 2.bubble sorting

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
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    display(a,size);
    getch();
    return 0;
}

//Insertion sorting


