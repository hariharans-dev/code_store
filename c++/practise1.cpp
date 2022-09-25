//bubble sort
#include<iostream>
#include<conio.h>
using namespace std;
int a[]={3,4,56,2,22,12,34,5,534,23};
int n=10;
int b[10];
void bubblesort()
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}
void selection_sort()
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
}
void insertion_sort()
{
	for(int i=1;i<n-1;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				int k;
				for(int k=i;k>j;k--)
					a[k]=a[k-1];
				a[k]=temp;
				break;
			}
}
void merge_sort()
{
	int c=n/2;
	for(int i=0;i<c-1;i++)
		for(int j=0;i<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(int i=c;i<n-1;i++)
		for(int j=c;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	int i=0,j=c,k=0;
	while((i<c)&&(j<n))
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	while(j<n)
		b[k++]=a[j++];
	while(i<c)
		b[k++]=a[i++];
}
void display()
{
	for(int i=0;i<n;i++)
		cout<<b[i]<<" ";
}
int main()
{
	merge_sort();
	display();
	getch();
	return 0;
}
//10.10.5.17./upload