#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int pos;
    char name[20];
    char id[12];
    char mob[15];
    struct node *next;
};

struct node *head,*store;


void insert(int pos,char name[20],char id[12],char mob[15])
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->pos=pos;
    strcpy(temp->name,name);
    strcpy(temp->id,id);
    strcpy(temp->mob,mob);
    temp->next=NULL;
    if(pos==1)
    {
        temp->next=head;
        head=temp;
        store=temp;
    }
    else
    {
        int i;
        store=head;
        for(i=1; i<pos-1; i++)
        {
            store=store->next;
        }
        temp->next=store->next;
        store->next=temp;
    }
}

void print()
{
    struct node *p=head;
    int d=1;
    if(p==NULL)
    {
        printf("\n\t***There is no record on the list***\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d. ",d);
            printf("%s\t",p->name);
            printf("%s\t",p->id);
            printf("%s\n",p->mob);
            p=p->next;
            d++;
        }
    }
}

void delet(int pos)
{
    struct node *p=head;
    if(pos==1)
    {
        head=head->next;
    }
    else
    {
        int i;
        store=head;
        for(i=1; i<pos-1; i++)
        {
            store=store->next;
        }
        store->next=store->next->next;

    }
}

void updaten(int pos,char name[20])
{
    struct node *p=head;
    if(pos==1)
    {
        strcpy(p->name,name);
    }
    else
    {
        int i;
        p=head;
        for(i=1; i<pos; i++)
        {
            p=p->next;
        }
        strcpy(p->name,name);
    }
}

void updatei(int pos,char id[])
{
    struct node *p=head;
    if(pos==1)
    {
        strcpy(p->id,id);
    }
    else
    {
        int i;
        p=head;
        for(i=1; i<pos; i++)
        {
            p=p->next;
        }
        strcpy(p->id,id);
    }
}

void updatem(int pos,char mo[15])
{
    struct node *p=head;
    if(pos==1)
    {
        strcpy(p->mob,mo);
    }
    else
    {
        int i;
        p=head;
        for(i=1; i<pos; i++)
        {
            p=p->next;
        }
        strcpy(p->mob,mo);
    }
}

int main()
{
    printf("\t\t\t\t\t***Student Enrollment***\n\n\n");
    int a;
    for(a=0; a<1; a++)
    {
        printf("1. Insert a student's information.\n");
        printf("2. Delete a student's information.\n");
        printf("3. Update a student's information.\n");
        printf("4. Print the record list.\n");
        printf("5. Exit program\n");
        printf("\nEnter your choice: ");
        int b;
        scanf("%d",&b);
        if(b==1)
        {
            char name[20],id[12],mob[15];
            int c;
            printf("\n\nEnter the student's serial number on the list: ");
            scanf("%d",&c);
            printf("\nEnter the student's name: ");
            scanf("%s",name);
            printf("\nEnter the student's ID: ");
            scanf("%s",id);
            printf("\nEnter the student's Mobile number: ");
            scanf("%s",mob);
            insert(c,name,id,mob);
        }
        else if(b==2)
        {
            printf("\nEnter the position number from the list you want to delete: ");
            int r;
            scanf("%d",&r);
            delet(r);
        }
        else if(b==3)
        {
            printf("1. Update Name.\n");
            printf("2. Update ID.\n");
            printf("3. Update Mobile number.\n");
            printf("\nEnter your choice what you want to update: ");
            int k;
            scanf("%d",&k);
            if(k==1)
            {
                char nam[20];
                int p;
                printf("\nEnter the position no on the list you wanted to update: ");
                scanf("%d",&p);
                printf("\nEnter the updated name: ");
                scanf("%s",nam);
                updaten(p,nam);
            }
            else if(k==2)
            {
                char id1[12];
                int p;
                printf("\nEnter the position no on the list you wanted to update: ");
                scanf("%d",&p);
                printf("\nEnter the updated id: ");
                scanf("%s",id1);
                updatei(p,id1);
            }
            else if(k==3)
            {
                char mo[15];
                int p;
                printf("\nEnter the position no on the list you wanted to update: ");
                scanf("%d",&p);
                printf("\nEnter the updated Mobile number: ");
                scanf("%s",mo);
                updatem(p,mo);
            }
        }
        else if(b==4)
        {
            print();
        }
        else if(b==5)
        {
            printf("\n");
            return 0;
        }
        int e;
        printf("\nPress 1 to continue: ");
        scanf("%d",&e);
        printf("\n");
        a=a-e;
    }
    return 0;
}
