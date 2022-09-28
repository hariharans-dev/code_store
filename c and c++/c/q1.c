#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int n,n1,n90=0,ihead=0,dhead=0;
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
}*tail,*head,*cnode,*temp,*head1,*tail1,*temp1,*temp2;
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
            strcpy(tail->reg_num,a);ihead+=9;
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
                tail=cnode;
            }
        }
    }
    printf("\n");
}
void display()
{
    temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        if(n==0)
            break;
        printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
        temp=temp->next;
    }
}
void rev_display()
{
    printf("\n");int i;
    for(i=n;i>0;i--)
    {
        temp=head;int j;
        for(j=1;j<i;j++)
            temp=temp->next;
        printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
    }
}
void deletion(int index)
{
    if(index==0)
    {
        head=head->next;dhead+=1;
        temp=head;
    }
    else if(index==(n-1))
    {
        temp2=head;int i;
        while(temp2->next!=tail)
            temp2=temp2->next;
        temp2->next=NULL;
        tail=temp2;
        temp=NULL;
    }
    else
    {
        temp2=head;int i;
        for(i=0;i<index-1;i++)
            temp2=temp2->next;
        temp2->next=temp2->next->next;
        temp=temp2->next;
    }
}
void avg()
{
    temp=head;
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    head1=cnode;
    tail1=cnode;
    while(temp!=NULL)
    {
        if(temp->average>90)
        {
            if(n90==0)
            {
                strcpy(tail1->reg_num,temp->reg_num);ihead+=9;
                strcpy(tail1->stud_name,temp->stud_name);
                tail1->average=temp->average;
                tail1->grade=temp->grade;
                tail1->mark1=temp->mark1;
                tail1->mark2=temp->mark2;
                tail1->mark3=temp->mark3;
            }
            else
            {
                cnode=(struct student*)malloc(sizeof(struct student));
                cnode->next=NULL;
                strcpy(cnode->reg_num,temp->reg_num);
                strcpy(cnode->stud_name,temp->stud_name);
                cnode->average=temp->average;
                cnode->grade=temp->grade;
                cnode->mark1=temp->mark1;
                cnode->mark2=temp->mark2;
                cnode->mark3=temp->mark3;
                tail1->next=cnode;
                tail1=cnode;
            }
            int index=0;
            temp1=head;
            while(temp1!=temp)
            {
                temp1=temp1->next;
                index++;
            }   
            deletion(index);
            n--;
            n90++;
        }
        else 
            temp=temp->next;
    }
}
void display90()
{
    temp=head1;
    if(n90==0)
        printf("There is no student with average of 90\n");
    while(temp!=NULL)
    {
        if(n90==0)
            break;
        printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
        temp=temp->next;
    }
}
int main()
{
    printf("1. Creation\n\n");
    creation();
    printf("2. Traverse and print the nodes from first to last\n");
    display();
    printf("3. Traverse and print the nodes from last to first\n");
    rev_display();
    printf("4. Find and create node of student average greater than 90 and delete it from the original node\n\n");
    avg();
    display90();
    printf("5. Traverse and print the remaining elements from the updated list\n");
    display();
    printf("6. The number of times the values of the head node is changed during insertion: \n\n");
    printf("The count is %d\n\n",ihead);
    printf("7. The number of times the values of the tail node is changed during deletion: \n\n");
    printf("The count is %d\n",dhead);
    getch();
    return 0;
}
