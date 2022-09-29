#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int n,n1,n90=0,n40=0,ihead=0;
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
};struct student *tail,*head,*temp,*cnode,*temp2,*temp3,*head1,*tail1,*head2,*tail2;
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
    head=cnode;
    tail=cnode;
    printf("Enter the number of students: ");
    scanf("%d",&n);n1=n;
    for(int i=0;i<n1;i++)
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
                    tail->next=cnode;
                    tail=cnode;
                    printf("\n");
                }
                else
                {
                    cnode->next=head;
                    head=cnode;
                    printf("\n");
                }
            }
        }
    }
    tail->next=head;
}
void greater_90()
{
    cnode=(struct student*)malloc(sizeof(struct student));
    struct student *tempn;
    cnode->next=NULL;
    head1=cnode;
    tail1=cnode;
    tempn=head;
    while(tempn!=tail)
    {
        if((tempn->mark1>90)&&(tempn->mark2>90)&&(tempn->mark3>90))
        {
            if(n90==0)
            {
                strcpy(cnode->reg_num,tempn->reg_num);ihead+=9;
                strcpy(cnode->stud_name,tempn->stud_name);
                cnode->average=tempn->average;
                cnode->grade=tempn->grade;
                cnode->mark1=tempn->mark1;
                cnode->mark2=tempn->mark2;
                cnode->mark3=tempn->mark3;
            }
            else
            {
                cnode=(struct student*)malloc(sizeof(struct student));
                cnode->next=head1;
                strcpy(cnode->reg_num, temp->reg_num);
                strcpy(cnode->stud_name, temp->stud_name);
                cnode->average = tempn->average;
                cnode->grade = tempn->grade;
                cnode->mark1 = tempn->mark1;
                cnode->mark2 = tempn->mark2;
                cnode->mark3 = tempn->mark3;
                tail1->next = cnode;
                tail1 = cnode;
            }
            n90++;
        }
        tempn=tempn->next;
    }  
    if((tempn->mark1>90)&&(tempn->mark2>90)&&(tempn->mark3>90))
    {
        cnode=(struct student*)malloc(sizeof(struct student));
        cnode->next=NULL;
        strcpy(cnode->reg_num,tempn->reg_num);
        strcpy(cnode->stud_name,tempn->stud_name);
        cnode->average=tempn->average;
        cnode->grade=tempn->grade;
        cnode->mark1=tempn->mark1;
        cnode->mark2=tempn->mark2;
        cnode->mark3=tempn->mark3;
        tail1->next=cnode;
        tail1=cnode;
        n90++;
    }  
}
void deletion(int index)
{
    if(index==0)
    {
        head=head->next;
        tail->next=head;
    }
    else if(index==(n-1))
    {
        temp2=head;
        for(int i=0;i<(n-1);i++)
            temp2=temp2->next;
        temp2->next=head;
        tail=temp2;
    }
    else
    {
        temp2=head;
        for(int i=0;i<index-1;i++)
            temp2=temp2->next;
        temp2->next=temp2->next->next;
    }
}
void less_40()
{
    cnode=(struct student*)malloc(sizeof(struct student));
    cnode->next=NULL;
    head2=cnode;
    tail2=cnode;
    temp=head;
    while(temp!=tail)
    {
        if((temp->mark1<40)&&(temp->mark2<40)&&(temp->mark3<40)) 
        {
            if(n40==0)
            {
                strcpy(cnode->reg_num,temp->reg_num);ihead+=9;
                strcpy(cnode->stud_name,temp->stud_name);
                cnode->average=temp->average;
                cnode->grade=temp->grade;
                cnode->mark1=temp->mark1;
                cnode->mark2=temp->mark2;
                cnode->mark3=temp->mark3;
            }
            else
            {
                cnode=(struct student*)malloc(sizeof(struct student));
                cnode->next=head1;
                strcpy(cnode->reg_num,temp->reg_num);
                strcpy(cnode->stud_name,temp->stud_name);
                cnode->average=temp->average;
                cnode->grade=temp->grade;
                cnode->mark1=temp->mark1;
                cnode->mark2=temp->mark2;
                cnode->mark3=temp->mark3;
                tail2->next=cnode;
                tail2=cnode;
            }
            n40++;
            temp2=head;int index=0;
            while(temp2!=temp)
            {
                index++;
                temp2=temp2->next;
            }
            deletion(index);
            n--;
        }
        temp=temp->next;
    }
    if((temp->mark1<40)&&(temp->mark2<40)&&(temp->mark3<40)) 
        {
            if(n40==0)
            {
                strcpy(cnode->reg_num,temp->reg_num);ihead+=9;
                strcpy(cnode->stud_name,temp->stud_name);
                cnode->average=temp->average;
                cnode->grade=temp->grade;
                cnode->mark1=temp->mark1;
                cnode->mark2=temp->mark2;
                cnode->mark3=temp->mark3;
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
                tail2->next=cnode;
                tail2=cnode;
            }
            n40++;
            temp2=head;int index=0;
            while(temp2!=temp)
            {
                index++;
                temp2=temp2->next;
            }
            deletion(index);
            n--;
        }
}
int display1()
{
    if(n90==0)
        return 0;
    temp2=head1;
    while(temp2!=NULL)
    {
         printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp2->reg_num,temp2->stud_name,temp2->average,temp2->grade);
        temp2=temp2->next;
    }
    printf("\n");
    return 1;
}
void display()
{
    temp=head;
    while(temp!=tail)
    {
        printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
        temp=temp->next;
    }
    printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
}
void display40()
{
    temp2=head2;
    printf("\nMarks less than 40 \n\n");
    while(temp2!=NULL)
    {
        printf("Regno: %s \nName: %s \navg: %f \ngrade: %c\n\n",temp->reg_num,temp->stud_name,temp->average,temp->grade);
        temp2=temp2->next;
    }
}
int main()
{
    printf("a. Creation\n\n");
    creation();
    printf("b. count the head node value changed\n\n");
    printf("The count is %d\n\n",ihead);
    printf("c. Marks greater than 90\n\n");
    greater_90();
    printf("Traverse\n\n");
    display();
    printf("d. dlelete Marks less than 40\n\n");
    printf("Remaining elements: \n");
    less_40();
    display();
    printf("e. count the head node value changed\n\n");
    printf("Count: %d\n\n",ihead);
    getch();
    return 0;
}