#include<stdio.h>
#include<conio.h>
#include<string.h>
struct student
{
    char stud_name[60];
    char reg_num[10];
    int mark1;
    int mark2;
    int mark3;
    int total;
    float average;
    char grade;
    struct student *next;
}*tail,*head,*cnode,*temp;
int repetition(char a[])
{
    temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->reg_num,a)==0)
            return 1;
        temp=temp->next;
    }
    return 0;
}
void creation()
{
    int n,n1;
    print("Enter number of nodes: ");
    scanf("%d",&n);n1=n;
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    for(int i=0;i<n1;i++)
    {
        if(i==0)
        {
            
        }
    }
}
