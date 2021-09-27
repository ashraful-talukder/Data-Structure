#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[20];
    char id[12];
    float num;
    struct node *next;
};

struct node *head,*store;
int i=0;

void insert(char name[20],char id[12],float num)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    strcpy(temp->id,id);
    temp->num=num;
    temp->next=NULL;
    if(i==0)
    {
        i=1;
        head=temp;
        store=temp;
    }
    else
    {
        store->next=temp;
        store=store->next;
    }
}

void print()
{
    struct node *p=head;
    int c=1;
    while(p!=NULL)
    {
        printf("%d. ",c);
        printf("%s\t",p->name);
        printf("%s\t",p->id);
        printf("%.2f\n",p->num);
        p=p->next;
        ++c;
    }
}

void delet(char l[12])
{
    struct node *var=head,*m;
    if(var==head && strcmp(var->id,l)==0)
    {
        head=head->next;
        var=head;
    }
    else
    {
        while(var!=NULL)
        {
            if(strcmp(var->id,l)==0)
            {
                m->next=var->next;
                var=var->next;
            }
            else
            {
                m=var;
                var=var->next;
            }
        }
    }
}

int main()
{
    int s;
    for(s=0; s<1; s++)
    {
        printf("1. Insert a student's information\n2. Delete a student's information\n3. Update a student's information\n4. Print the list\n");
        int a;
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a==1)
        {
            char name[20],id[12];
            float num;
            printf("\nEnter the student's name: ");
            scanf("%s",name);
            printf("\nEnter the student's ID: ");
            scanf("%s",id);
            printf("\nEnter the total marks he obtained: ");
            scanf("%f",&num);
            insert(name,id,num);
        }
        else if(a==2)
        {
            printf("Enter the id of the student you want to delete: ");
            char l[12];
            scanf("%s",l);
            delet(l);
        }
        else if(a==3)
        {
            print();
            printf("Enter the student's serial no on the list: ");
            int r;
            scanf("%d",&r);
            printf("\nWhat you want to update?\n1.Name\2.ID\n3.Marks\nEnter your choice: ");
            int q;
            if(q==1)
            {
                char nam[20];
                scanf("%s",nam);

            }
            else if(q==2)
            {

            }
            else if(q==3)
            {

            }
        }
        else if(a==4)
        {
            print();
        }
        else
        {
            printf("\n\n\t***You entered a wrong choice***\n\n");
            return 0;
        }
        printf("\nEnter 1 for continue: ");
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            s=s-k;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void swap(int x,int y)
{
    struct node *n=head,*m,*p;
    char nam[20],i[12],no[15];
    while(n!=NULL)
    {
        if(n->pos==x)
        {
            m=n;
        }
        else if(n->pos==y)
        {
            p=n;
        }
       p=p->next;
    }
    strcpy(nam,m->name);
    strcpy(m->name,p->name);
    strcpy(p->name,nam);

    strcpy(i,m->id);
    strcpy(m->id,p->id);
    strcpy(p->id,i);

    strcpy(no,m->mob);
    strcpy(m->mob,p->mob);
    strcpy(p->mob,no);
}
