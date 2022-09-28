#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int n,n1;
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
}*tail,*head,*temp,*cnode,*temp2,*temp3;
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
char grade(float a)
{
    char g;
    if((a>=91)&&(a<=100))
        g='S';
    else if((a>=81)&&(a<=90))
        g='A';
    else if((a>=71)&&(a<=80))
        g='B';
    else if((a>=61)&&(a<=70))
        g='C';
    else if((a>=51)&&(a<=60))
        g='D';
    else if((a>=41)&&(a<=50))
        g='E';
    else if((a>=0)&&(a<=40))
        g='F';
    else 
        g='N';
    return g;
}
void creation()
{
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    printf("Enter the number of students: ");
    scanf("%d",&n);n1=n;
    for(int i=0;i<n1;i++)
    {
        char a[10];
        printf("Enter regno: ");
        scanf("%s",&a);
        if(i==0)
        {
            strcpy(tail->reg_num,a);
            printf("Enter name: ");
            scanf("%s",&tail->stud_name);
            printf("Enter mark1 mark2 mark3: ");
            scanf("%d %d %d",&tail->mark1,&tail->mark2,&tail->mark3);
            tail->total=tail->mark1+tail->mark1+tail->mark3;
            tail->average=tail->total/3;
            tail->grade=grade(tail->average);
            printf("\n");
        }
        else
        {
            cnode=(struct student*)malloc(sizeof(struct student));
            cnode->next=NULL;
            if(repetition(a)==1)
            {
                printf("The regno is repeated\n");
                n1++;
            }
            else
            {
                strcpy(cnode->reg_num,a);
                printf("Enter name: ");
                scanf("%s",&cnode->stud_name);
                printf("Enter mark1 mark2 mark3: ");
                scanf("%d %d %d",&cnode->mark1,&cnode->mark2,&cnode->mark3);
                cnode->total=cnode->mark1+cnode->mark1+cnode->mark3;
                cnode->average=cnode->total/3;
                cnode->grade=grade(cnode->average);
                if(i%2==0)
                {
                    cnode->next=head;
                    head=cnode;
                    printf("\n");
                }
                else
                {
                    tail->next=cnode;
                    tail=cnode;
                    printf("\n");
                }
            }
        }
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%s",temp->reg_num);
        temp=temp->next;
    }
}
int main()
{
    creation();
    display();
    getch();
    return 0;
}