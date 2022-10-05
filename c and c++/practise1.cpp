#include<iostream>
#include<conio.h>
using namespace std;
void display(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void bubble_sort(int a[],int size)
{
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
}
void selection_sort(int a[],int size)
{
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
}
void insertion_sort(int a[],int size)
{
    display(a,size);
}
void merge_sort(int a[],int size)
{
    int c=size/2;
    for(int i=0;i<c-1;i++)
        for(int j=i+1;j<c;j++)
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
    for(int i=c;i<size-1;i++)
        for(int j=i+1;j<size;j++)
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
    int i=0,j=c,k=0,b[size];
    while((i<c)&&(j<size))
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<c)
        b[k++]=a[i++];
    while(j<size)
        b[k++]=a[j++];
    display(b,size);
}
void 
int main()
{
    int a[]={101,99,88,100,77,76,40,32,33,10};int size=10;
    merge_sort(a,size);
    getch();
    return 0;
}