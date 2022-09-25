//1.

#include<iostream>
#include<conio.h>
using namespace std;
int n,n2=0;
struct node
{
    char name[60],reg[10],grade;
    int m1,m2,m3,tot;
    float avg;
    struct node *next;
}*head,*tail,*cnode,*temp,*temp1,*head1,*tail1;
int repetition(char a[])
{
    temp=head;
    while(temp!=NULL)
    {
        int s=1;
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]!=temp->reg[i])
            {
                s=0;
                break;
            }
        }
        if(s==1)
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
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->next=NULL;
    tail=cnode;
    head=cnode;
    int n1,m1,m2,m3,tot;float a;
    char re[10];
    cout<<"Enter the number of students: ";cin>>n;n1=n;
    for(int i=0;i<n1;i++)
    {
        cout<<"enter the regno: ";cin>>re;
        if(i==0)
        {
            int j;
            for(j=0;re[j]!='\0';j++)
                tail->reg[j]=re[j];
            tail->reg[j]='\0';
            cout<<"Enter the student name: ";cin>>tail->name;
            cout<<"Enter the three marks: ";cin>>m1>>m2>>m3;
            tot=m1+m2+m3;
            a=tot/3;
            tail->grade=grade(a);
            tail->tot=tot;
            tail->m1=m1;
            tail->m2=m2;
            tail->m3=m3;
            tail->avg=a;
        }
        else
        {
            if(repetition(re)==1)
            {
                cout<<"The student regno is repeated"<<endl;
                n1++;
            }
            else
            {
                cnode=(struct node*)malloc(sizeof(struct node));
                cnode->next=NULL;
                int j;
                for(j=0;re[j]!='\0';j++)
                    cnode->reg[j]=re[j];
                cnode->reg[j]='\0';
                cout<<"Enter the student name: ";cin>>cnode->name;
                cout<<"Enter the three marks: ";cin>>m1>>m2>>m3;
                tot=m1+m2+m3;
                a=tot/3;
                cnode->grade=grade(a);
                cnode->tot=tot;
                cnode->m1=m1;
                cnode->m2=m2;
                cnode->m3=m3;
                cnode->avg=a;
                tail->next=cnode;
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
        cout<<"Regno: "<<temp->reg<<"\nName: "<<temp->name<<"\nTotal: "<<temp->tot<<"\nGrade: "<<temp->grade<<endl;
        cout<<endl;
        temp=temp->next;
    }
}
void rev_display()
{
    for(int i=n;i>0;i--)
    {
        temp=head;
        for(int j=1;j<i;j++)
            temp=temp->next;
        cout<<"Regno: "<<temp->reg<<"\nName: "<<temp->name<<"\nTotal: "<<temp->tot<<"\nGrade: "<<temp->grade<<endl;
        cout<<endl;
    }   
}
void deletion_avg()
{
    cnode=(struct node*)malloc(sizeof(struct node));
    cnode->next=NULL;
    head1=cnode;
    tail1=cnode;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->avg>90)
        {
            if(n2==0)
            {
                tail1->avg=temp->avg;
                tail1->grade=temp->grade;
                tail1->m1=temp->m1;
                tail1->m2=temp->m2;
                tail1->m3=temp->m3;
                tail1->tot=temp->tot;
                int i;
                for(i=0;temp->name[i]!='\0';i++)
                    tail1->name[i]=temp->name[i];
                tail->name[i]='\0';
                i=0;
                for(i=0;temp->reg[i]!='\0';i++)
                    tail1->reg[i]=temp->reg[i];
                tail->reg[i]='\0';
            }
            else
            {
                cnode=(struct node*)malloc(sizeof(struct node));
                cnode->next=NULL;
                cnode->avg=temp->avg;
                cnode->grade=temp->grade;
                cnode->m1=temp->m1;
                cnode->m2=temp->m2;
                cnode->m3=temp->m3;
                cnode->tot=temp->tot;
                int i=0;
                for(i=0;temp->name[i]!='\0';i++)
                    cnode->name[i]=temp->name[i];
                cnode->name[i]='\0';
                i=0;
                for(i=0;temp->reg[i]!='\0';i++)
                    cnode->reg[i]=temp->reg[i];
                cnode->reg[i]='\0';
                tail1->next=cnode;
                tail1=cnode;
            }
            n2++;
        }
        temp=temp->next;
    }
}
void display2()
{
    temp=head1;
    while((temp!=NULL)&&(n2>0))
    {
        cout<<"Regno: "<<temp->reg<<"\nName: "<<temp->name<<"\nTotal: "<<temp->tot<<"\nGrade: "<<temp->grade<<endl;
        cout<<endl;
        temp=temp->next;
    }
}
int main()
{
    creation();
    deletion_avg();
    display2();
    getch();
    return 0;
}
