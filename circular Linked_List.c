#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
    int n;
    struct linklist *next;
}node;

node *head='\0';
void delLast();
void display();
void create();
node* search(int);
void addFirst();
void addLast();
void delFirst();

void create()
{
    node *h,*t;
    int x;
    char ch;
    do
    {
        printf("Enter the value: ");
        scanf("%d", &x);
        t=(node*)malloc(sizeof(node));
        t->n=x;
        if(head=='\0')
            head=t;
        else
            h->next=t;
        t->next=head;
        h=t;
        printf("Do you want to continue ? ");
        fflush(stdin);
        ch=getchar();
    }
    while(ch=='Y' || ch=='y');
}

void display()
{
    node *h=head;
    if(head=='\0')
    {
        printf("List is Empty");
        return;
    }
    do
    {
        printf("%5d", h->n);
        h=h->next;
    }
    while(h!=head);
}

node* search(int x)
{
    node *h=head;
    do
    {
        if(h->n==x)
            return h;
        h=h->next;
    }
    while(h!=head);
    return '\0';
}

void addFirst()
{
    node *t,*h; int x;
    printf("Enter the new number: ");
    scanf("%d", &x);
    t=(node*)malloc(sizeof(node));
    t->n=x;
    if(head=='\0')
    {
        head=t;
        head->next=head;
        return;
    }
    h=head;
    while(h->next!=head)
        h=h->next;
    t->next=head;
    head=t;
    h->next=head;
}

void addLast()
{
    node *t,*h; int x;
    printf("Enter the new number: ");
    scanf("%d", &x);
    t=(node*)malloc(sizeof(node));
    t->n=x;
    if(head=='\0')
    {
        head=t;
        head->next=head;
        return;
    }
    h=head;
    while(h->next!=head)
        h=h->next;
    h->next=t;
    t->next=head;
}

void delFirst()
{
    node *q,*h=head;;
    if(head=='\0')
    {
        printf("Empty node, can't delete");
        return;
    }
    if(head->next==head)
    {
        head='\0';
        free(h);
        return;
    }
    while(h->next!=head)
        h=h->next;
    q=head;
    h->next=q->next;
    head=head->next;
    free(q);
}

void delLast()
{
    node *q,*h=head;;
    if(head=='\0')
    {
        printf("Empty node, can't delete");
        return;
    }
    if(head->next==head)
    {
        head='\0';
        free(h);
        return;
    }
    while(h->next->next!=head)
        h=h->next;
    q=head;
    q=h->next;
    h->next=head;
    free(q);
}

void menu()
{
    printf("\n");
    printf("\t\t\t PROGRAM ON LINKLIST\n");
    printf("\t\t\t   1. Create\n");
    printf("\t\t\t   2. Del Last\n");
    printf("\t\t\t   3. Display\n");
    printf("\t\t\t   4. Search\n");
    printf("\t\t\t   5. Del First\n");
    printf("\t\t\t   6. Add First\n");
    printf("\t\t\t   7. Add Last\n");
    printf("\t\t\t   8. Exit\n");
    printf("\t\t\tENTER YOUR CHOISE  ");
}

int main()
{
    int ch,y;
    node *a;
    while(4)
    {
        menu();
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                   creat();
                   break;
            case 2:
                   delLast();
                   break;
            case 3:
                   display();
                   break;
            case 4:
                   printf("Enter the Search Element ");
                   scanf("%d", &y);
                   a=search(y);
                   if(a=='\0')
                      printf("NOT found");
                   else
                      printf("FOUND, The address is %u", a);
                   break;
            case 5:
                   delFirst();
                   break;
            case 6:
                   addFirst();
                   break;
            case 7:
                   addLast();
                   break;

            case 8:
                   exit(4);
                   break;
            default:
                   printf("Invalid Input");
        }
    }
}
