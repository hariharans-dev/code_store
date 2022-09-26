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
	struct student *next,*prev;
}*tail,*head,*temp,*cnode;
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
    else if((a>0)&&(a<=40))
        g='F';
    else 
        g='N';
    return g;
}
void creation()
{
    printf("Enter number of nodes: ");
    scanf("%d",&n);n1=n;
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    cnode->prev=NULL;
    tail=cnode;
    head=cnode;
    int i;
    for(i=0;i<n1;i++)
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
        }
        else
        {
            cnode=(struct student*)malloc(sizeof(struct student));
            cnode->next=NULL;
            cnode->prev=NULL;
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
                tail->next=cnode;
                cnode->prev=tail;
                tail=cnode;
            }
        }
    }
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
		temp=temp->next;
	}
}
void rev_display()
{
	temp=tail;
	while(temp!=NULL)
	{
		printf("%s ",temp->reg_num);
		temp=temp->prev;
	}
}
int main()
{
	creation();
	display();
	getch();
	return 0;
}